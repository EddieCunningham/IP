#include "BMIP.h"


void EMPedigreeOptimizer::_log_initialize(const vector<pedigreeClass2*> & trainingSet_, string problemType, bool printPeople, bool initializeRoots, bool initializeEmission, bool initializeTransition) {
    
    _trainingSet = trainingSet_;
    
    // initialize the _emissionProbs and _transitionProbs
    bool sexDependent = _trainingSet.at(0)->sexDependent;

    int femaleN = -1;
    int maleN = -1;
    int unknownN = -1;
    
    int index=0;
    
    for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {

        pedigreeClass2* pedigree = *ped_it;
        if(pedigree->bredthFirstList.size() == 0) {
            pedigree->makeBFL();
        }

        if(printPeople) {
            (*ped_it)->printAllPeople("z"+to_string(index)+"z");
        }
        
        if(sexDependent != (*ped_it)->sexDependent) {
            // cout << "NEED SAME SEX DEPENDENCY!!" << endl;
            cout << "Failed at line: " << __LINE__ << endl;
            raise(SIGABRT);
        }
        
        for(auto p_it=(*ped_it)->allPeople.begin(); p_it!=(*ped_it)->allPeople.end(); ++p_it) {
            
            if((*p_it)->parentA && (*p_it)->parentA->sex == "unknown") {
                // cout << "DONT SUPPORT THIS CASE YET" << endl;
                cout << "Failed at line: " << __LINE__ << endl;
                raise(SIGABRT);
            }
            
            string sex = (*p_it)->sex;
            int n = (*p_it)->n;
            
            if(sex == "male") {
                if(maleN != -1) {
                    if(maleN != n) {
                        // cout << "INCONSISTENT " << maleN << endl;
                        cout << "Failed at line: " << __LINE__ << endl;
                        raise(SIGABRT);
                    }
                }
                else {
                    maleN = n;
                }
            }
            else if(sex == "female") {
                if(femaleN != -1) {
                    if(femaleN != n) {
                        // cout << "INCONSISTENT " << femaleN << endl;
                        cout << "Failed at line: " << __LINE__ << endl;
                        raise(SIGABRT);
                    }
                }
                else {
                    femaleN = n;
                }
            }
            else if(sex == "unknown") {
                if(unknownN != -1) {
                    if(unknownN != n) {
                        // cout << "INCONSISTENT " << unknownN << endl;
                        cout << "Failed at line: " << __LINE__ << endl;
                        raise(SIGABRT);
                    }
                }
                else {
                    unknownN = n;
                }
            }
            else {
                // cout << "INVALID SEX!!" << endl;
                cout << "Failed at line: " << __LINE__ << endl;
                raise(SIGABRT);
            }
        }
        ++index;
    }
    
    _femaleN = femaleN;
    _maleN = maleN;
    _unknownN = unknownN;
    if(unknownN == -1) {
        // no unknown people
        unknownN = 0;
        _unknownN = 0;
    }
    _sexDependent = sexDependent;
    
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
    
    if(sexDependent) {
        // sex is one of ['female','male','unknown']
        if(initializeEmission) {
            _emissionProbs = vector<vector<vector<double>>>(3);
            _emissionProbs.at(0) = vector<vector<double>>(femaleN,vector<double>(_emissionMapping.size()));
            _emissionProbs.at(1) = vector<vector<double>>(maleN,vector<double>(_emissionMapping.size()));
            _emissionProbs.at(2) = vector<vector<double>>(unknownN,vector<double>(_emissionMapping.size()));
        }
        
        // WILL ASSUME THAT THERE ARE NO UNKNOWN,UNKNOWN -> CHILD FAMILIES
        if(initializeTransition) {
            _transitionProbs = vector<vector<vector<vector<double>>>>(3);
            _transitionProbs.at(0) = vector<vector<vector<double>>>(femaleN,vector<vector<double>>(maleN,vector<double>(maleN)));
            _transitionProbs.at(1) = vector<vector<vector<double>>>(femaleN,vector<vector<double>>(maleN,vector<double>(femaleN)));
            _transitionProbs.at(2) = vector<vector<vector<double>>>(femaleN,vector<vector<double>>(maleN,vector<double>(unknownN)));
        }
    }
    else {
        // emmision can be ['shaded', 'possiblyShaded', 'unshaded', 'carrier']
        if(initializeEmission) {
            _emissionProbs = vector<vector<vector<double>>>(1);
            _emissionProbs.at(0) = vector<vector<double>>(maleN,vector<double>(_emissionMapping.size()));
        }
        if(initializeTransition) {
            _transitionProbs = vector<vector<vector<vector<double>>>>(1);
            _transitionProbs.at(0) = vector<vector<vector<double>>>(femaleN,vector<vector<double>>(maleN,vector<double>(maleN)));
        }
    }
    
    /*
     ========================================================
     */

    if(initializeRoots) {
        
        // initialize the _rootProbs
        for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {
            
            vector<vector<double>> rootsToAdd;
            for(auto r_it=(*ped_it)->roots.begin(); r_it!=(*ped_it)->roots.end(); ++r_it) {
                
                int n = (*r_it)->n;
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


    // initialize the _transitionProbs
    // sum over motherChrom fatherChrom should sum to 1 for each childSex
    for(int i=0; i<_transitionProbs.size(); ++i) {
        
        vector<vector<double>> sums = vector<vector<double>>();

        vector<vector<vector<double>>> g;
        personClass* foundPerson;

        for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {

            pedigreeClass2* pedigree = *ped_it;
            bool found = false;
            
            for(auto p_it=pedigree->allPeople.begin(); p_it!=pedigree->allPeople.end(); ++p_it) {

                personClass* person = *p_it;
                int sexIndex = _getSexIndex(pedigree,person);
                if(sexIndex == i && person->g.size()>0) {
                    g = person->g;
                    found = true;
                    foundPerson = person;
                    break;
                }
            }
            if(found) {
                break;
            }
        }
        
        if(initializeTransition) {

            double noiseOrder = 4;

            for(int j=0; j<_transitionProbs.at(i).size(); ++j) {
                sums.push_back(vector<double>(_transitionProbs.at(i).at(j).size(),0));
                
                for(int k=0; k<_transitionProbs.at(i).at(j).size(); ++k) {
                    
                    for(int l=0; l<_transitionProbs.at(i).at(j).at(k).size(); ++l) {
                        double randomNumb = 0;//rand()/(double)RAND_MAX*pow(10,-noiseOrder);
                        double gPlusNoise = g.at(l).at(k).at(j) + randomNumb;

                        _transitionProbs.at(i).at(j).at(k).at(l) = gPlusNoise;
                        sums.at(j).at(k) += gPlusNoise;
                    }
                }
            }
            for(int j=0; j<_transitionProbs.at(i).size(); ++j) {
                for(int k=0; k<_transitionProbs.at(i).at(j).size(); ++k) {
                    for(int l=0; l<_transitionProbs.at(i).at(j).at(k).size(); ++l) {
                        _transitionProbs.at(i).at(j).at(k).at(l) /= sums.at(j).at(k);
                    }
                }
            }
        }
    }
    
    unordered_map<string,vector<vector<int>>> initialProbs(
        {
            {
                "AD",{{0,1,2},{0,1,2},{0,1,2}}
            },
            {
                "AR",{{3},{3},{3}}
            },
            {
                "XLR",{{0},{0,1},{0,1,2}}
            }
        }
        );
    if(initialProbs.find(problemType) == initialProbs.end()) {
        cout << "Failed at line: " << __LINE__ << endl;
        cout << "Invalid problem type.  Was expecting \"AD\", \"AR\" or \"XLR\"" << endl;
        raise(SIGABRT);
    }

    vector<vector<int>> allIndices = initialProbs.at(problemType);
    double shadedProb = 1.0;
    double unshadedProb = 1 - shadedProb;

    // sum over shading observations should equal 1
    // initialize the _emissionProbs
    if(initializeEmission) {

        for(int i=0; i<_emissionProbs.size(); ++i) {

            vector<int> indices = allIndices.at(i);
            for(int j=0; j<_emissionProbs.at(i).size(); ++j) {

                if(find(indices.begin(),indices.end(),j) != indices.end()) {
                    _emissionProbs.at(i).at(j).at(0) = shadedProb;
                    _emissionProbs.at(i).at(j).at(1) = unshadedProb;
                }
                else {
                    _emissionProbs.at(i).at(j).at(0) = unshadedProb;
                    _emissionProbs.at(i).at(j).at(1) = shadedProb;
                }
            }
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
        
        vector<vector<pair<int,double>>> people = vector<vector<pair<int,double>>>();
        vector<vector<double>> people2 = vector<vector<double>>();
        for(auto p_it=(*ped_it)->allPeople.begin(); p_it!=(*ped_it)->allPeople.end(); ++p_it) {
            
            int N = (*p_it)->n;
            vector<pair<int,double>> toAdd = vector<pair<int,double>>(N,pair<int,double>(false,0));
            people.push_back(toAdd);
            vector<double> toAdd2 = vector<double>(N,0);
            people2.push_back(toAdd2);
        }
        _log_u.push_back(people);
        _log_c.push_back(people2);   


        int numFams = (int)(*ped_it)->families.size();

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


        for(int f=0; f<(*ped_it)->families.size(); ++f) {
            
            int numbChildren = (int)(*ped_it)->families.at(f).size()-2;
            vector<vector<pair<int,double>>> lastBPart;
            vector<vector<vector<double>>> lastEPart;
            if(_sexDependent) {

                lastBPart = vector<vector<pair<int,double>>>(numbChildren,
                                    vector<pair<int,double>>(3,pair<int,double>(false,0)));

                lastEPart = vector<vector<vector<double>>>(numbChildren,
                                    vector<vector<double>>({
                                            vector<double>(_femaleN),
                                            vector<double>(_maleN),
                                            vector<double>(_unknownN)}));
            }
            else {
                lastBPart = vector<vector<pair<int,double>>>(numbChildren,
                                    vector<pair<int,double>>(1,pair<int,double>(false,0)));

                lastEPart = vector<vector<vector<double>>>(numbChildren,
                                    vector<vector<double>>(1,
                                            vector<double>(_femaleN)));
            }
            
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
    vector<vector<double>> sums;

    for(int i=0; i<_transitionProbs.size(); ++i) {
        for(int j=0; j<_transitionProbs.at(i).size(); ++j) {
            sums.push_back(vector<double>(_transitionProbs.at(i).at(j).size(),0));
            
            for(int k=0; k<_transitionProbs.at(i).at(j).size(); ++k) {
                
                for(int l=0; l<_transitionProbs.at(i).at(j).at(k).size(); ++l) {

                    double noise = rand()/(double)RAND_MAX*pow(10,-noiseOrder);
                    _transitionProbs.at(i).at(j).at(k).at(l) += noise;
                    sums.at(j).at(k) += _transitionProbs.at(i).at(j).at(k).at(l);
                }
            }
        }
        for(int j=0; j<_transitionProbs.at(i).size(); ++j) {
            for(int k=0; k<_transitionProbs.at(i).at(j).size(); ++k) {
                for(int l=0; l<_transitionProbs.at(i).at(j).at(k).size(); ++l) {
                    _transitionProbs.at(i).at(j).at(k).at(l) /= sums.at(j).at(k);
                }
            }
        }
    }
}

void EMPedigreeOptimizer::_train(const vector<pedigreeClass2*> & trainingSet, string problemType, bool printPeople, bool printWork, bool rootProbUpdate, bool emissionProbUpdate, bool transitionProbUpdate, bool initializeRoots, bool initializeEmission, bool initializeTransition) {

    srand(time(NULL));
    
    if(!_firstUpdate) {
        initializeRoots = true;
        initializeEmission = true;
        initializeTransition = true;
        _firstUpdate = true;
    }
    _log_initialize(trainingSet,problemType,printPeople,initializeRoots,initializeEmission,initializeTransition);

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

void EMPedigreeOptimizer::_trainRoots(const vector<pedigreeClass2*> & testSet, string problemType, bool printPeople, bool printWork) {

    _rootProbs = vector<vector<vector<double>>>();

    bool reInitializeRoots = true;
    bool reInitializeEmission = false;
    bool reInitializeTransition = false;

    bool rootProbUpdate = true;
    bool emissionProbUpdate = false;
    bool transitionProbUpdate = false;

    _train(testSet,problemType,printPeople,printWork,rootProbUpdate,emissionProbUpdate,transitionProbUpdate,reInitializeRoots,reInitializeEmission,reInitializeTransition);
    
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

        person->log_viterbiProbs = vector<double>(person->probs.size(),-1);
    }

    vector<personClass*> currentSet;

    // update the initial roots
    for(personClass* root: pedigree->roots) {

        double maxVal = UNIQUE_ZERO_ID;
        double argmaxVal = 0;

        bool set = false;

        for(int i=0; i<root->log_viterbiProbs.size(); ++i) {

            double rootProb = _getRootProb(pedigree,root,i);
            double emissionProb = _getEmissionProb(pedigree,root,i);
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

                double emissionProb = _getEmissionProb(pedigree,person,k);
                double maxV = UNIQUE_ZERO_ID;
                bool set2 = false;

                for(int i=0; i<mother->log_viterbiProbs.size(); ++i) {
                        
                    double log_motherProb = mother->log_viterbiProbs.at(i);
                    for(int j=0; j<father->log_viterbiProbs.size(); ++j) {

                        double transitionProb = _getTransitionProb(pedigree,person,i,j,k);
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
            double maxTransitionProb = _getTransitionProb(pedigree,person,motherState,fatherState,person->mostLikelyState);

            double emissionProb = _getEmissionProb(pedigree,person,person->mostLikelyState);

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

void EMPedigreeOptimizer::_calculateViterbiStates(pedigreeClass2* pedigree, string problemType, bool printPeople, bool printWork) {

    _trainRoots(vector<pedigreeClass2*>({pedigree}),problemType,printPeople,printWork);

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
            double emissionProb = _getEmissionProb(pedigree,person,state);
            double transProb = _getTransitionProb(pedigree, person, motherState, fatherState, state);

            if(printWork) {
                cout << "Person " << person->_id << " has state " << state;
                cout << " and has transition probs (" << motherState << "," << fatherState << ") -> " << state << ": " << transProb;
                cout << " and emission prob: " << emissionProb << endl;
            }
        }
        else {

            int state = person->mostLikelyState;
            double emissionProb = _getEmissionProb(pedigree,person,state);
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







