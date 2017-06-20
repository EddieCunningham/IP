#include "BMIP.h"


void EMPedigreeOptimizer::_log_initialize(const vector<pedigreeClass2*> & trainingSet_, bool printPeople, bool initializeRoots, bool initializeEmission, bool initializeTransition) {
    
    _trainingSet = trainingSet_;
    
    int index=0;

    _femaleN = _getN("female");
    _maleN = _getN("male");
    _unknownN = _getN("unknown");
    
    for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {

        pedigreeClass2* pedigree = *ped_it;
        if(pedigree->bredthFirstList.size() == 0) {
            pedigree->makeBFL();
        }

        if(printPeople) {
            pedigree->printAllPeople("z"+to_string(index)+"z");
        }

        for(auto p_it=pedigree->allPeople.begin(); p_it!=pedigree->allPeople.end(); ++p_it) {

            personClass* person = *p_it;
            string sex = person->sex;
            
            if(person->parentA && person->parentA->sex == "unknown") {
                // cout << "DONT SUPPORT THIS CASE YET" << endl;
                cout << "Failed at line: " << __LINE__ << endl;
                raise(SIGABRT);
            }
            if(sex != "male" && sex != "female" && sex != "unknown") {
                cout << "Failed at line: " << __LINE__ << endl;
                cout << "Invalid sex!" << endl;
                raise(SIGABRT);
            }
            int n = _getN(person);
        }
        ++index;
    }
    
    if(printPeople) {
        string toPrint = "\nvector<pedigreeClass2*> trainingSet({";
        
        index = 0;
        for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {
            if(index+1 != _trainingSet.size()) {
                toPrint += "&pedigreez"+to_string(index)+"z"+",";
            }
            else {
                toPrint += "&pedigreez"+to_string(index)+"z";
            }
            ++index;
        }
        toPrint += "});\n";
        toPrint += "EMPedigreeOptimizer empo;\n";
        cout << toPrint;
    }

    if(initializeEmission) {
        _emissionProbs = vector<vector<vector<double>>>(_nSexIndices);

        for(int s=0; s<_nSexIndices; ++s) {
            string sex = _sexOrder.at(s);
            int l = _getL(sex);
            int m = _getM(sex);
            int n = _getN(sex);
            int divider = _problemName == "autosome" ? m : m;

            vector<vector<double>> currentEmission = vector<vector<double>>(n,vector<double>(_emissionMapping.size()));

            if(_emissionMapping.size() != 2) {
                cout << "Failed at line: " << __LINE__ << endl;
                cout << "Can't handle this yet!!" << endl;
                raise(SIGABRT);
            }

            double top,bottom;
            if(_isDominant) {
                top = _shadedProb;
                bottom = 1 - _shadedProb;
            }
            else {
                top = 1 - _shadedProb;
                bottom = _shadedProb;
            }
            for(int i=0; i<n; ++i) {
                if(i < divider) {
                    currentEmission.at(i).at(0) = top;
                    currentEmission.at(i).at(1) = bottom;
                }
                else {
                    currentEmission.at(i).at(0) = bottom;
                    currentEmission.at(i).at(1) = top;
                }
            }
            _emissionProbs.at(s) = currentEmission;
        }
    }
    if(initializeTransition) {
        _transitionProbs = vector<vector<vector<vector<double>>>>(_nSexIndices);
        int femaleN = _getN("female");
        int maleN = _getN("male");
        for(int s=0; s<_nSexIndices; ++s) {
            string sex = _sexOrder.at(s);
            int childN = _getN(sex);
            const vector<vector<vector<double>>>& relevantG = _allG.at("female,male->"+sex);
            vector<vector<vector<double>>> currentTransitions = vector<vector<vector<double>>>(femaleN,vector<vector<double>>(maleN,vector<double>(childN)));
            for(int i=0; i<femaleN; ++i) {
                for(int j=0; j<maleN; ++j) {
                    double sum = 0.0;
                    for(int k=0; k<childN; ++k) {
                        double val = relevantG.at(k).at(j).at(i);
                        currentTransitions.at(i).at(j).at(k) = val;
                        sum += val;
                    }
                    if(abs(sum-1.0) > PRECISION) {
                        cout << "Failed at line: " << __LINE__ << endl;
                        cout << "Failed in initializing transition probs!" << endl;
                        cout << "Sum was: " << sum << endl;
                        raise(SIGABRT);
                    }
                }
            }
            _transitionProbs.at(s) = currentTransitions;
        }

    }
    if(initializeRoots) {
        
        // initialize the _rootProbs
        for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {
            
            vector<vector<double>> rootsToAdd;
            for(auto r_it=(*ped_it)->roots.begin(); r_it!=(*ped_it)->roots.end(); ++r_it) {
                
                personClass* root = *r_it;

                int n = _getN(root);
                vector<double> rootToAdd(n);
                double total = 0.0;
                for(int i=0; i<n; ++i) {
                    double randomNumb = 1;//rand()/(double)RAND_MAX;
                    total += randomNumb;
                    rootToAdd.at(i) = randomNumb;
                }
                for(int i=0; i<n; ++i) {
                    rootToAdd.at(i) /= total;
                }
                rootsToAdd.push_back(rootToAdd);
            }
            _rootProbs.push_back(rootsToAdd);
        }
    }


    _log_u = vector<vector<vector<pair<int,double>>>>();
    _log_w = vector<vector<vector<vector<vector<pair<int,double>>>>>>();
    _log_a = vector<vector<vector<vector<pair<int,double>>>>>();
    _log_b = vector<vector<vector<vector<vector<vector<pair<int,double>>>>>>>();

    _log_c = vector<vector<vector<double>>>();
    _log_d = vector<vector<vector<vector<double>>>>();
    _log_e = vector<vector<vector<vector<vector<vector<vector<double>>>>>>>();
    
    for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {

        pedigreeClass2* pedigree = *ped_it;
        
        vector<vector<pair<int,double>>> people = vector<vector<pair<int,double>>>();
        vector<vector<double>> people2 = vector<vector<double>>();
        for(auto p_it=pedigree->allPeople.begin(); p_it!=pedigree->allPeople.end(); ++p_it) {

            personClass* person = *p_it;
            
            int n = _getN(person);
            vector<pair<int,double>> toAdd = vector<pair<int,double>>(n,pair<int,double>(false,0));
            people.push_back(toAdd);
            vector<double> toAdd2 = vector<double>(n,0);
            people2.push_back(toAdd2);
        }
        _log_u.push_back(people);
        _log_c.push_back(people2);   


        int numFams = (int)pedigree->families.size();

        vector<vector<vector<vector<pair<int,double>>>>> vAddition(numFams,
                          vector<vector<vector<pair<int,double>>>>({
                                  vector<vector<pair<int,double>>>(_femaleN,vector<pair<int,double>>(_maleN,pair<int,double>(false,0))),
                                  vector<vector<pair<int,double>>>(_maleN,vector<pair<int,double>>(_femaleN,pair<int,double>(false,0)))}));

        vector<vector<vector<pair<int,double>>>> aAddition(numFams,
                          vector<vector<pair<int,double>>>({
                                  vector<pair<int,double>>(_femaleN,pair<int,double>(false,0)),
                                  vector<pair<int,double>>(_maleN,pair<int,double>(false,0))}));

        vector<vector<vector<vector<vector<pair<int,double>>>>>> bAddition = vector<vector<vector<vector<vector<pair<int,double>>>>>>(numFams,
                                                                                   vector<vector<vector<vector<pair<int,double>>>>>(_femaleN,
                                                                                           vector<vector<vector<pair<int,double>>>>(_maleN)));

        vector<vector<vector<double>>> dAddition(numFams,
                          vector<vector<double>>(_femaleN,
                                  vector<double>(_maleN)));

        vector<vector<vector<vector<vector<vector<double>>>>>> eAddition = vector<vector<vector<vector<vector<vector<double>>>>>>(numFams,
                                                                                   vector<vector<vector<vector<vector<double>>>>>(_femaleN,
                                                                                           vector<vector<vector<vector<double>>>>(_maleN)));


        for(int f=0; f<pedigree->families.size(); ++f) {
            
            int numbChildren = (int)(*ped_it)->families.at(f).size()-2;
            vector<vector<pair<int,double>>> lastBPart;
            vector<vector<vector<double>>> lastEPart;
            
            lastBPart = vector<vector<pair<int,double>>>(numbChildren,
                                vector<pair<int,double>>(_nSexIndices,pair<int,double>(false,0)));

            vector<vector<double>> inE;
            for(int s=0; s<_nSexIndices; ++s) {
                string sex = _sexOrder.at(s);
                int n = _getN(sex);
                inE.push_back(vector<double>(n));
            }
            lastEPart = vector<vector<vector<double>>>(numbChildren,inE);


            for(int i=0; i<_femaleN; ++i) {
                for(int j=0; j<_maleN; ++j) {
                    bAddition.at(f).at(i).at(j) = lastBPart;
                    eAddition.at(f).at(i).at(j) = lastEPart;
                }
            }
        }
        
        _log_w.push_back(vAddition);
        _log_a.push_back(aAddition);
        _log_b.push_back(bAddition);
        _log_d.push_back(dAddition);
        _log_e.push_back(eAddition);   
    }
}

void EMPedigreeOptimizer::_log_EMStep2(bool rootProbUpdate, bool emissionProbUpdate, bool transitionProbUpdate) {
    _resetDataStructures();
    double dummy;
    _log_eStep2(dummy);
    _log_mStep2(rootProbUpdate, emissionProbUpdate, transitionProbUpdate);
}

void EMPedigreeOptimizer::_transitionProbHack() {

    int noiseOrder = 6;

    for(int i=0; i<_transitionProbs.size(); ++i) {
        for(int j=0; j<_transitionProbs.at(i).size(); ++j) {
            for(int k=0; k<_transitionProbs.at(i).at(j).size(); ++k) {
                
                double sum = 0.0;
                for(int l=0; l<_transitionProbs.at(i).at(j).at(k).size(); ++l) {

                    double noise = rand()/(double)RAND_MAX*pow(10,-noiseOrder);
                    _transitionProbs.at(i).at(j).at(k).at(l) += noise;
                    sum += _transitionProbs.at(i).at(j).at(k).at(l);
                }
                for(int l=0; l<_transitionProbs.at(i).at(j).at(k).size(); ++l) {
                    _transitionProbs.at(i).at(j).at(k).at(l) /= sum;
                }
            }
        }
    }

    for(int j=0; j<_emissionProbs.size(); ++j) {
        for(int k=0; k<_emissionProbs.at(j).size(); ++k) {
            
            double sum = 0.0;
            for(int l=0; l<_emissionProbs.at(j).at(k).size(); ++l) {

                double noise = rand()/(double)RAND_MAX*pow(10,-noiseOrder);
                _emissionProbs.at(j).at(k).at(l) += noise;
                sum += _emissionProbs.at(j).at(k).at(l);
            }
            for(int l=0; l<_emissionProbs.at(j).at(k).size(); ++l) {
                _emissionProbs.at(j).at(k).at(l) /= sum;
            }
        }
    }
}

void EMPedigreeOptimizer::_train(const vector<pedigreeClass2*> & trainingSet, bool printPeople, bool printWork, bool rootProbUpdate, bool emissionProbUpdate, bool transitionProbUpdate, bool initializeRoots, bool initializeEmission, bool initializeTransition) {

    srand(time(NULL));
    
    if(!_firstUpdate) {
        initializeRoots = true;
        initializeEmission = true;
        initializeTransition = true;
        _firstUpdate = true;
    }
    _log_initialize(trainingSet,printPeople,initializeRoots,initializeEmission,initializeTransition);

    _transitionProbHack();

    double stopPoint = pow(10,-6);

    int nLoops = 0;
    while(true) {
        
        vector<vector<vector<double>>> emissionProbsOld = _emissionProbs;
        vector<vector<vector<double>>> rootProbsOld = _rootProbs;
        vector<vector<vector<vector<double>>>> transitionProbsOld = _transitionProbs;

        _log_EMStep2(rootProbUpdate, emissionProbUpdate, transitionProbUpdate);
        
        vector<double> diffs = _leastSquaresDiff(rootProbsOld, transitionProbsOld, emissionProbsOld);
        double total = diffs.at(0)+diffs.at(1)+diffs.at(2);
        if(printWork) {
            cout << "total: " << total << endl;
        }
        if(total < stopPoint) {
            _emissionProbs = emissionProbsOld;
            _rootProbs = rootProbsOld;
            _transitionProbs = transitionProbsOld;
            break;
        }
        ++nLoops;
    }
}

void EMPedigreeOptimizer::_trainRoots(const vector<pedigreeClass2*> & testSet, bool printPeople, bool printWork) {

    _rootProbs = vector<vector<vector<double>>>();

    bool reInitializeRoots = true;
    bool reInitializeEmission = false;
    bool reInitializeTransition = false;

    bool rootProbUpdate = true;
    bool emissionProbUpdate = false;
    bool transitionProbUpdate = false;

    _train(testSet,printPeople,printWork,rootProbUpdate,emissionProbUpdate,transitionProbUpdate,reInitializeRoots,reInitializeEmission,reInitializeTransition);
    
    if(printWork) {
        cout << "Learned roots for pedigree " << _trainingSet.at(0)->filename << ":" << endl;
    }
    for(int i=0; i<_trainingSet.at(0)->roots.size(); ++i) {

        personClass* root = _trainingSet.at(0)->roots.at(i);
        vector<double> distribution = _rootProbs.at(0).at(i);
        if(printWork) {
            cout << "Id: " << root->_id << " :  ";
            for(auto &&d:distribution) {
                cout << d << " ";
            }
            cout << endl;
        }
    }
}

double EMPedigreeOptimizer::_calcProb() {
    double log_probability;
    _resetDataStructures();
    _log_eStep2(log_probability);
    if(log_probability == UNIQUE_ZERO_ID) {
        return 0;
    }
    return exp(log_probability);
}


void EMPedigreeOptimizer::_viterbiUpdate(pedigreeClass2* pedigree) {

    double log_mostLikelyStateProb = 0.0;


    for(personClass* person: pedigree->allPeople) {

        person->log_viterbiProbs = vector<double>(_getN(person),-1);
    }

    vector<personClass*> currentSet;

    // update the initial roots
    for(personClass* root: pedigree->roots) {

        double maxVal = UNIQUE_ZERO_ID;
        double argmaxVal = 0;

        bool set = false;

        for(int i=0; i<root->log_viterbiProbs.size(); ++i) {

            double rootProb = _getRootProb(pedigree,root,i);
            double emissionProb = _getEmissionProb(root,i);
            double log_currentProb;
            if(rootProb == 0 || emissionProb == 0) {
                log_currentProb = UNIQUE_ZERO_ID;
            }
            else {
                log_currentProb = log(rootProb) + log(emissionProb);
            }

            if(log_currentProb != UNIQUE_ZERO_ID) {
                if(!set) {
                    maxVal = log_currentProb;
                    argmaxVal = i;
                    set = true;
                }
                else if(log_currentProb > maxVal) {
                    maxVal = log_currentProb;
                    argmaxVal = i;
                }
            }

            root->log_viterbiProbs.at(i) = log_currentProb;
        }

        root->viterbiConfidence = maxVal;
        root->mostLikelyState = argmaxVal;

        // keep track of the total probability of this state
        log_mostLikelyStateProb = _safeAdd(log_mostLikelyStateProb, maxVal);
    
        for(int i=0; i<root->mateKids.size(); ++i) {

            vector<personClass*> children = root->mateKids.at(i).second;
            
            for(personClass* child: children) {
                if(find(currentSet.begin(),currentSet.end(),child) == currentSet.end()) {
                    currentSet.push_back(child);
                }
            }
        }
    }


    while(currentSet.size() > 0) {

        vector<personClass*> nextSet;

        for(personClass* person: currentSet) {

            personClass* mother = _getMother(person);
            personClass* father = _getFather(person);

            if(mother->mostLikelyState == -1 || father->mostLikelyState == -1) {

                if(find(nextSet.begin(),nextSet.end(),person) == nextSet.end()) {
                    nextSet.push_back(person);
                    continue;
                }
            }
            
            double maxVal = UNIQUE_ZERO_ID;
            double argmaxVal = 0;
            bool set = false;

            for(int k=0; k<person->log_viterbiProbs.size(); ++k) {

                double emissionProb = _getEmissionProb(person,k);
                double maxV = UNIQUE_ZERO_ID;
                bool set2 = false;

                for(int i=0; i<mother->log_viterbiProbs.size(); ++i) {
                        
                    double log_motherProb = mother->log_viterbiProbs.at(i);
                    for(int j=0; j<father->log_viterbiProbs.size(); ++j) {

                        double transitionProb = _getTransitionProb(person,i,j,k);
                        double log_fatherProb = father->log_viterbiProbs.at(j);

                        double totalProb;

                        if(transitionProb == UNIQUE_ZERO_ID || log_motherProb == UNIQUE_ZERO_ID || log_fatherProb == UNIQUE_ZERO_ID) {
                            totalProb = UNIQUE_ZERO_ID;
                        }
                        else {
                            totalProb = log(transitionProb) + log_motherProb + log_fatherProb;
                        }

                        if(totalProb != UNIQUE_ZERO_ID) {
                            if(!set2) {
                                maxV = totalProb;
                                set2 = true;
                            }
                            else if(totalProb > maxV) {
                                maxV = totalProb;
                            }
                        }
                    }
                }

                double log_currentProb;
                if(emissionProb == 0 || maxV == UNIQUE_ZERO_ID) {
                    log_currentProb = UNIQUE_ZERO_ID;
                }
                else {
                    log_currentProb = log(emissionProb) + maxV;
                }

                if(log_currentProb != UNIQUE_ZERO_ID) {
                    if(!set) {
                        maxVal = log_currentProb;
                        argmaxVal = k; 
                        set = true;
                    }
                    else if(log_currentProb > maxVal) {
                        maxVal = log_currentProb;
                        argmaxVal = k; 
                    }
                }

                person->log_viterbiProbs.at(k) = log_currentProb;
            }

            person->viterbiConfidence = maxVal;
            person->mostLikelyState = argmaxVal;

            int motherState = _getMother(person)->mostLikelyState;
            int fatherState = _getFather(person)->mostLikelyState;
            double maxTransitionProb = _getTransitionProb(person,motherState,fatherState,person->mostLikelyState);

            double emissionProb = _getEmissionProb(person,person->mostLikelyState);

            log_mostLikelyStateProb = _safeAdd(log_mostLikelyStateProb, log(emissionProb));
            log_mostLikelyStateProb = _safeAdd(log_mostLikelyStateProb, log(maxTransitionProb));

            for(int i=0; i<person->mateKids.size(); ++i) {

                vector<personClass*> children = person->mateKids.at(i).second;
                
                for(personClass* child: children) {
                    if(find(nextSet.begin(),nextSet.end(),child) == nextSet.end()) {
                        nextSet.push_back(child);
                    }
                }
            }
                        
        }

        currentSet = nextSet;
    }

    pedigree->mostLikelyStateProb = _safeExp(log_mostLikelyStateProb);
}

void EMPedigreeOptimizer::_calculateViterbiStates(pedigreeClass2* pedigree, bool printPeople, bool printWork) {

    _trainRoots(vector<pedigreeClass2*>({pedigree}),printPeople,printWork);

    // run the viterbi algorithm
    _viterbiUpdate(pedigree);

    if(printWork) {
        cout << endl;
    }

    for(personClass* person: pedigree->bredthFirstList) {

        if(person->parentA) {
            int motherState = _getMother(person)->mostLikelyState;
            int fatherState = _getFather(person)->mostLikelyState;
            int state = person->mostLikelyState;
            double emissionProb = _getEmissionProb(person,state);
            double transProb = _getTransitionProb( person, motherState, fatherState, state);

            if(printWork) {
                cout << "Person " << person->_id << " has state " << state;
                cout << " and has transition probs (" << motherState << "," << fatherState << ") -> " << state << ": " << transProb;
                cout << " and emission prob: " << emissionProb << endl;
            }
        }
        else {

            int state = person->mostLikelyState;
            double emissionProb = _getEmissionProb(person,state);
            double rootProb = _getRootProb(pedigree, person, state);

            if(printWork) {
                cout << "Person " << person->_id << " has state " << state;
                cout << " and has initial prob " << rootProb;
                cout << " and emission prob: " << emissionProb << endl;
            }
        }
    }

    if(printWork) {
        cout << endl;
        for(personClass* person: pedigree->leaves) {
            cout << "Leaf " << person->_id << " has prob of " << _safeExp(person->viterbiConfidence) << endl;
        }
    }

    double stateProb = pedigree->mostLikelyStateProb;
    double expectedProb = _calcProb();

    if(printWork) {
        cout << "\nThe probability of the most likely state is: " << stateProb << endl;
        cout << "The expected probability of the IP is: " << expectedProb << endl;
    }
}







