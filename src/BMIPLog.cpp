#include "BMIP.h"


bool logCompare(double log_a, double log_b) {
    // makes sure that log_a and log_b are close enough together
    double diff;
    if(log_a > log_b) {
        diff = log_a + log1p(-exp(log_b - log_a));
    }
    else {
        diff = log_b + log1p(-exp(log_a - log_b));
    }
    return diff < -LOG_PRECISION;
}

void EMPedigreeOptimizer::log_initialize(const vector<pedigreeClass2*> & trainingSet_, bool printPeople) {
    
    _trainingSet = trainingSet_;
    
    // initialize the _emissionProbs and _transitionProbs
    bool sexDependent = _trainingSet.at(0)->sexDependent;
    int femaleN = -1;
    int maleN = -1;
    int unknownN = -1;
    
    int index=0;
    
    for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {
        
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
        toPrint += "empo.initialize(trainingSet,false);\n";
        // cout << toPrint;
    }
    
    if(sexDependent) {
        // sex is one of ['female','male','unknown']
        _emissionProbs = vector<vector<vector<double>>>(3);
        _emissionProbs.at(0) = vector<vector<double>>(femaleN,vector<double>(4));
        _emissionProbs.at(1) = vector<vector<double>>(maleN,vector<double>(4));
        _emissionProbs.at(2) = vector<vector<double>>(unknownN,vector<double>(4));
        
        // WILL ASSUME THAT THERE ARE NO UNKNOWN,UNKNOWN -> CHILD FAMILIES
        _transitionProbs = vector<vector<vector<vector<double>>>>(3);
        _transitionProbs.at(0) = vector<vector<vector<double>>>(femaleN,vector<vector<double>>(maleN,vector<double>(maleN)));
        _transitionProbs.at(1) = vector<vector<vector<double>>>(femaleN,vector<vector<double>>(maleN,vector<double>(femaleN)));
        _transitionProbs.at(2) = vector<vector<vector<double>>>(femaleN,vector<vector<double>>(maleN,vector<double>(unknownN)));
    }
    else {
        // emmision can be ['shaded', 'possiblyShaded', 'unshaded', 'carrier']
        _emissionProbs = vector<vector<vector<double>>>(1);
        _emissionProbs.at(0) = vector<vector<double>>(maleN,vector<double>(4));
        _transitionProbs = vector<vector<vector<vector<double>>>>(1);
        _transitionProbs.at(0) = vector<vector<vector<double>>>(femaleN,vector<vector<double>>(maleN,vector<double>(maleN)));
    }
    
    /*
     ========================================================
     */
    
    // initialize the _rootProbs
    for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {
        
        vector<vector<double>> rootsToAdd;
        for(auto r_it=(*ped_it)->roots.begin(); r_it!=(*ped_it)->roots.end(); ++r_it) {
            
            int n = (*r_it)->n;
            vector<double> rootToAdd(n);
            // randomly initialize (for the moment)
            double total = 0.0;
            for(int i=0; i<n; ++i) {
                double randomNumb = rand()/(double)RAND_MAX;
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
    
    // initialize the _transitionProbs
    // sum over motherChrom fatherChrom should sum to 1 for each childSex
    for(int i=0; i<_transitionProbs.size(); ++i) {
        
        vector<vector<double>> sums = vector<vector<double>>();
        
        for(int j=0; j<_transitionProbs.at(i).size(); ++j) {
            sums.push_back(vector<double>(_transitionProbs.at(i).at(j).size(),0));
            
            for(int k=0; k<_transitionProbs.at(i).at(j).size(); ++k) {
                
                for(int l=0; l<_transitionProbs.at(i).at(j).at(k).size(); ++l) {
                    double randomNumb = rand()/(double)RAND_MAX;
                    _transitionProbs.at(i).at(j).at(k).at(l) = randomNumb;
                    sums.at(j).at(k) += randomNumb;
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
    
    
    
    // sum over shading observations should equal 1
    // initialize the _emissionProbs
    for(int i=0; i<_emissionProbs.size(); ++i) {
        for(int j=0; j<_emissionProbs.at(i).size(); ++j) {
            double sum = 0.0;
            for(int k=0; k<_emissionProbs.at(i).at(j).size(); ++k) {
                double randomNumb = rand()/(double)RAND_MAX;
                sum += randomNumb;
                _emissionProbs.at(i).at(j).at(k) = randomNumb;
            }
            for(int k=0; k<_emissionProbs.at(i).at(j).size(); ++k) {
                _emissionProbs.at(i).at(j).at(k) /= sum;
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


// _u -> [pedigree (d)][person (c)][chromosome (k)] -> u_k(c)
double EMPedigreeOptimizer::_getLogUVal(pedigreeClass2* pedigree, int d, personClass* child, int k) {

    int c = pedigree->mapToIndexAllPeople.at(child);

    pair<int,double> spot = _log_u.at(d).at(c).at(k);
    int status = spot.first;
    if(status == 0) {
        _computeLogUVal(pedigree,d,child,k);
    }
    else if(status == 2) {
        // cout << "ALREADY COMPUTING VALUE" << endl;
        cout << "Failed at line: " << __LINE__ << endl;
        raise(SIGABRT);
    }
    else if(status == 3) {
        return UNIQUE_ZERO_ID;
    }
    double uVal = _log_u.at(d).at(c).at(k).second;
    return uVal;
}

// _w -> [pedigree (d)][familyUnit (f)][p==mother][parentAChromosome (i)][parentBChromosome (j)] -> w_ij(q|p)
double EMPedigreeOptimizer::_getLogWVal(pedigreeClass2* pedigree, int d, int f, int motherIsP, int i, int j) {

    pair<int,double> spot = _log_w.at(d).at(f).at(motherIsP).at(i).at(j);
    int status = spot.first;
    if(status == 0) {
        _computeLogWVal(pedigree,d,f,motherIsP,i,j);
    }
    else if(status == 2) {
        // cout << "ALREADY COMPUTING VALUE" << endl;
        cout << "Failed at line: " << __LINE__ << endl;
        raise(SIGABRT);
    }
    else if(status == 3) {
        return UNIQUE_ZERO_ID;
    }
    double uVal = _log_w.at(d).at(f).at(motherIsP).at(i).at(j).second;
    return uVal;
}

// _a -> [pedigree (d)][familyUnit (f)][p==mother][parentAChromosome (i)] -> a_i(p,q)
double EMPedigreeOptimizer::_getLogAVal(pedigreeClass2* pedigree, int d, int f, int motherIsP, int i) {

    pair<int,double> spot = _log_a.at(d).at(f).at(motherIsP).at(i);
    int status = spot.first;
    if(status == 0) {
        _computeLogAVal(pedigree,d,f,motherIsP,i);
    }
    else if(status == 2) {
        // cout << "ALREADY COMPUTING VALUE" << endl;
        cout << "Failed at line: " << __LINE__ << endl;
        raise(SIGABRT);
    }
    else if(status == 3) {
        return UNIQUE_ZERO_ID;
    }
    double uVal = _log_a.at(d).at(f).at(motherIsP).at(i).second;
    return uVal;
}

// _b -> [pedigree (d)][familyUnit (f)][motherChromosome (i)][fatherChromosome (j)][childNumber (c)][childSexIndex] -> b_ij(c)
double EMPedigreeOptimizer::_getLogBVal(pedigreeClass2* pedigree, int d, int f, int i, int j, personClass* child, int c) {
    
    int sexIndex = getSexIndex(pedigree,child);
    pair<int,double> spot = _log_b.at(d).at(f).at(i).at(j).at(c).at(sexIndex);
    int status = spot.first;
    if(status == 0) {
        _computeLogBVal(pedigree,d,f,i,j,child,c);
    }
    else if(status == 2) {
        // cout << "ALREADY COMPUTING VALUE" << endl;
        cout << "Failed at line: " << __LINE__ << endl;
        raise(SIGABRT);
    }
    else if(status == 3) {
        return UNIQUE_ZERO_ID;
    }
    double uVal = _log_b.at(d).at(f).at(i).at(j).at(c).at(sexIndex).second;
    return uVal;

}

// _a -> [pedigree (d)][familyUnit (f)][p==mother][parentAChromosome (i)] -> a_i(p,q)
void EMPedigreeOptimizer::_computeLogAVal(pedigreeClass2* pedigree, int d, int f, int motherIsP, int i) {

    if(_log_a.at(d).at(f).at(motherIsP).at(i).first == 1 || _log_a.at(d).at(f).at(motherIsP).at(i).first == 3) {
        return;
    }
    else if(_log_a.at(d).at(f).at(motherIsP).at(i).first == 2) {
        // cout << "can't happen" << endl;
        cout << "Failed at line: " << __LINE__ << endl;
        raise(SIGABRT);
    }
    _log_a.at(d).at(f).at(motherIsP).at(i).first = 2;

    const vector<personClass*>& family = pedigree->families.at(f);
    personClass* mother = family.at(0);
    personClass* father = family.at(1);

    personClass* p;
    personClass* q;
    if(motherIsP) {
        p = mother;
        q = father;
    }
    else {
        p = father;
        q = mother;
    }

    double log_u_i_p = _getLogUVal(pedigree,d,p,i);

    double log_mProd = 0.0;
    bool allZeroFlag = false;
    for(auto pair_it=p->mateKids.begin(); pair_it!=p->mateKids.end(); ++pair_it) {

        personClass* mate = pair_it->first;
        if(mate == q) {
            continue;
        }
        int mateN = mate->n;

        personClass* mother_;
        personClass* father_;
        sortMates(p,mate,mother_,father_);
        int newF = getFamNumb(pedigree,mother_,father_);

        logAddition sum;

        for(int i_=0; i_<mateN; ++i_) {

            double log_w_ii__mp = _getLogWVal(pedigree,d,newF,motherIsP,i,i_);
            if(log_w_ii__mp == UNIQUE_ZERO_ID) {
                continue;
            }
            sum.addPositiveLogPoint(log_w_ii__mp);
        }
        if(sum.needToInitialize) {
            allZeroFlag = true;
            break;
        }
        log_mProd += sum.log_ans;
    }

    if(log_u_i_p == UNIQUE_ZERO_ID || allZeroFlag) {
        _log_a.at(d).at(f).at(motherIsP).at(i).first = 3;
        _log_a.at(d).at(f).at(motherIsP).at(i).second = UNIQUE_ZERO_ID;
    }
    else {
        double log_val = log_u_i_p + log_mProd;

        _log_a.at(d).at(f).at(motherIsP).at(i).first = 1;
        _log_a.at(d).at(f).at(motherIsP).at(i).second = log_val;
    }
}

// _b -> [pedigree (d)][familyUnit (f)][motherChromosome (i)][fatherChromosome (j)][childNumber (c)][childSexIndex] -> b_ij(c)
void EMPedigreeOptimizer::_computeLogBVal(pedigreeClass2* pedigree, int d, int f, int i, int j, personClass* child, int c) {

    int sexIndex = getSexIndex(pedigree,child);

    if(_log_b.at(d).at(f).at(i).at(j).at(c).at(sexIndex).first == 1 || _log_b.at(d).at(f).at(i).at(j).at(c).at(sexIndex).first == 3) {
        return;
    }
    else if(_log_b.at(d).at(f).at(i).at(j).at(c).at(sexIndex).first == 2) {
        // cout << "can't happen" << endl;
        cout << "Failed at line: " << __LINE__ << endl;
        raise(SIGABRT);
    }

    _log_b.at(d).at(f).at(i).at(j).at(c).at(sexIndex).first = 2;

    int shadingIndex = _emissionMapping.at(child->typeOfShading);
    int childN = child->n;
    int motherIsP = (int)(child->sex=="female");

    logAddition log_val;

    for(int k=0; k<childN; ++k) {

        double A_ijk = _transitionProbs.at(sexIndex).at(i).at(j).at(k);
        double bVal = _emissionProbs.at(sexIndex).at(k).at(shadingIndex);

        double log_cProd = 0.0;
        bool allZeroFlag = false;

        for(auto pair_it=child->mateKids.begin(); pair_it!=child->mateKids.end(); ++pair_it) {

            personClass* mate = pair_it->first;
            personClass* mother;
            personClass* father;
            sortMates(child,mate,mother,father);
            int newF = getFamNumb(pedigree,mother,father);


            int mateN = mate->n;

            logAddition sum;
            for(int k_=0; k_<mateN; ++k_) {

                double log_w_kk__mc = _getLogWVal(pedigree,d,newF,motherIsP,k,k_);
                if(log_w_kk__mc == UNIQUE_ZERO_ID) {
                    continue;
                }
                sum.addPositiveLogPoint(log_w_kk__mc);
            }
            if(sum.needToInitialize) {
                allZeroFlag = true;
                break;
            }
            else {
                log_cProd += sum.log_ans;    
            }
        }
        if(allZeroFlag || A_ijk < PRECISION || bVal < PRECISION) {
            continue;
        }
        else {
            double combined = log(A_ijk) + log(bVal) + log_cProd;
            log_val.addPositiveLogPoint(combined);
        }
    }

    if(log_val.needToInitialize) {
        _log_b.at(d).at(f).at(i).at(j).at(c).at(sexIndex).first = 3;
        _log_b.at(d).at(f).at(i).at(j).at(c).at(sexIndex).second = UNIQUE_ZERO_ID;
    }
    else {
        _log_b.at(d).at(f).at(i).at(j).at(c).at(sexIndex).first = 1;
        _log_b.at(d).at(f).at(i).at(j).at(c).at(sexIndex).second = log_val.log_ans;
    }
}

// _u -> [pedigree (d)][person (c)][chromosome (k)] -> u_k(c)
void EMPedigreeOptimizer::_computeLogUVal(pedigreeClass2* pedigree, int d, personClass* child, int k) {

    int cIndex = pedigree->mapToIndexAllPeople.at(child);

    if(_log_u.at(d).at(cIndex).at(k).first == 1 || _log_u.at(d).at(cIndex).at(k).first == 3) {
        return;
    }
    else if(_log_u.at(d).at(cIndex).at(k).first == 2) {
        // cout << "Can't be doing this!" << endl;
        cout << "Failed at line: " << __LINE__ << endl;
        raise(SIGABRT);
    }
    _log_u.at(d).at(cIndex).at(k).first = 2;

    int shadingIndex = _emissionMapping.at(child->typeOfShading);
    int sexIndex = getSexIndex(pedigree,child);

    double log_val = -1;
    if(child->parentA == nullptr) {

        int rIndex = pedigree->mapToIndexRoots.at(child);
        double piVal = _rootProbs.at(d).at(rIndex).at(k);
        double bVal = _emissionProbs.at(sexIndex).at(k).at(shadingIndex);
        if(piVal < PRECISION || bVal < PRECISION) {
            log_val = -1;
        }
        else {
            log_val = log(piVal)+log(bVal);
        }
    }
    else {

        personClass* mother;
        personClass* father;
        sortMates(child->parentA,child->parentB,mother,father);

        int motherN = mother->n;
        int fatherN = father->n;
        
        
        int f = getFamNumb(pedigree,mother,father);
        const vector<personClass*>& family = pedigree->families.at(f);

        logAddition sum;
        for(int i=0; i<motherN; ++i) {

            double log_a_i_pq = _getLogAVal(pedigree,d,f,true,i);
            if(log_a_i_pq == UNIQUE_ZERO_ID) {
                continue;
            }
            for(int j=0; j<fatherN; ++j) {

                double A_ijk = _transitionProbs.at(sexIndex).at(i).at(j).at(k);
                double bVal = _emissionProbs.at(sexIndex).at(k).at(shadingIndex);
                double log_a_j_qp = _getLogAVal(pedigree,d,f,false,j);
                if(A_ijk < PRECISION || bVal < PRECISION || log_a_j_qp == UNIQUE_ZERO_ID) {
                    continue;
                }

                double log_sProd = 0.0;
                bool allZeroFlag = false;
                for(int s=0; s<family.size()-2; ++s) {

                    personClass* sibling = family.at(s+2);

                    if(sibling == child) {
                        continue;
                    }
                    double log_b_ij_s = _getLogBVal(pedigree,d,f,i,j,sibling,s);

                    if(log_b_ij_s == UNIQUE_ZERO_ID) {
                        allZeroFlag = true;
                        break;
                    }
                    
                    log_sProd += log_b_ij_s;
                }

                if(allZeroFlag) {
                    continue;
                }
                else {
                    double combined = log(A_ijk) + log(bVal) + log_a_i_pq + log_a_j_qp + log_sProd;
                    sum.addPositiveLogPoint(combined);
                }
            }
        }
        if(sum.needToInitialize) {
            log_val = -1;
        }
        else {
            log_val = sum.log_ans;
        }
    }

    if(log_val == -1) {
        _log_u.at(d).at(cIndex).at(k).first = 3;
        _log_u.at(d).at(cIndex).at(k).second = UNIQUE_ZERO_ID;
    }
    else {
        _log_u.at(d).at(cIndex).at(k).first = 1;
        _log_u.at(d).at(cIndex).at(k).second = log_val;
    }
}

// _w -> [pedigree (d)][familyUnit (f)][p==mother][parentAChromosome (i)][parentBChromosome (j)] -> w_ij(q|p)
void EMPedigreeOptimizer::_computeLogWVal(pedigreeClass2* pedigree, int d, int f, int motherIsP, int i, int j) {

    if(_log_w.at(d).at(f).at(motherIsP).at(i).at(j).first == 1 || _log_w.at(d).at(f).at(motherIsP).at(i).at(j).first == 3) {
        return;
    }
    else if(_log_w.at(d).at(f).at(motherIsP).at(i).at(j).first == 2) {
        // cout << "can't happen" << endl;
        cout << "Failed at line: " << __LINE__ << endl;
        raise(SIGABRT);
    }
    _log_w.at(d).at(f).at(motherIsP).at(i).at(j).first = 2;



    const vector<personClass*>& family = pedigree->families.at(f);
    personClass* mother = family.at(0);
    personClass* father = family.at(1);

    personClass* p;
    personClass* q;
    if(motherIsP) {
        p = mother;
        q = father;
    }
    else {
        p = father;
        q = mother;
    }

    double log_val = -1;

    bool isLeaf = find(pedigree->leaves.begin(),pedigree->leaves.end(),p) != pedigree->leaves.end();
    if(isLeaf) {
        log_val = 0.0;
    }
    else {

        double log_a_j_qp = _getLogAVal(pedigree,d,f,!motherIsP,j);
        if(log_a_j_qp == UNIQUE_ZERO_ID) {
            log_val = -1;
        }
        else {
            double log_cProd = 0.0;
            bool allZeroFlag = false;

            for(int c=0; c<family.size()-2; ++c) {

                personClass* child = family.at(c+2);
                double log_b_ij_c;
                if(motherIsP) {
                    log_b_ij_c = _getLogBVal(pedigree,d,f,i,j,child,c);
                }
                else {
                    log_b_ij_c = _getLogBVal(pedigree,d,f,j,i,child,c);
                }
                if(log_b_ij_c == UNIQUE_ZERO_ID) {
                    allZeroFlag = true;
                    break;
                }
                log_cProd += log_b_ij_c;
            }

            if(allZeroFlag) {
                log_val = -1;
            }
            else {
                log_val = log_a_j_qp + log_cProd;
            }
        }
    }

    if(log_val == -1) {
        _log_w.at(d).at(f).at(motherIsP).at(i).at(j).first = 3;
        _log_w.at(d).at(f).at(motherIsP).at(i).at(j).second = UNIQUE_ZERO_ID; 
    }
    else {
        _log_w.at(d).at(f).at(motherIsP).at(i).at(j).first = 1;
        _log_w.at(d).at(f).at(motherIsP).at(i).at(j).second = log_val; 
    }


}

void EMPedigreeOptimizer::_log_cUpdate() {

    int d = 0;
    for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {

        pedigreeClass2* pedigree = *ped_it;

        for(auto p_it=pedigree->allPeople.begin(); p_it!=pedigree->allPeople.end(); ++p_it) {

            personClass* person = *p_it;
            int personN = person->n;
            int pIndex = pedigree->mapToIndexAllPeople.at(person);

            logAddition log_total;
            for(int i=0; i<personN; ++i) {

                double log_u_i_p = _getLogUVal(pedigree,d,person,i);
                double log_mProd = 0.0;
                bool allZeroFlag = false;
                for(auto pair_it=person->mateKids.begin(); pair_it!=person->mateKids.end(); ++pair_it) {

                    personClass* mate = pair_it->first;
                    int mateN = mate->n;

                    personClass* mother;
                    personClass* father;
                    sortMates(person,mate,mother,father);
                    int f = getFamNumb(pedigree,mother,father);

                    logAddition log_sum;
                    for(int j=0; j<mateN; ++j) {

                        double log_w_ij_mp;
                        log_w_ij_mp = _getLogWVal(pedigree,d,f,(int)(person == mother),i,j);
                        if(log_w_ij_mp == UNIQUE_ZERO_ID) {
                            continue;
                        }
                        log_sum.addPositiveLogPoint(log_w_ij_mp);
                    }
                    if(log_sum.needToInitialize) {
                        allZeroFlag = true;
                        break;
                    }
                    log_mProd += log_sum.log_ans;
                }
                
                if(log_u_i_p == UNIQUE_ZERO_ID || allZeroFlag) {
                    _log_c.at(d).at(pIndex).at(i) = UNIQUE_ZERO_ID;
                }
                else {
                    double log_val = log_u_i_p + log_mProd;
                    _log_c.at(d).at(pIndex).at(i) = log_val;
                    log_total.addPositiveLogPoint(log_val);
                }
                
            }

            logAddition log_sum;
            for(int i=0; i<personN; ++i) {
                if(log_total.needToInitialize == false && _log_c.at(d).at(pIndex).at(i) != UNIQUE_ZERO_ID) {
                    if(log_total.needToInitialize) {
                        cout << "Failed at line: " << __LINE__ << endl;
                        cout << "Divided by zero!" << endl;
                        raise(SIGABRT);
                    }
                    _log_c.at(d).at(pIndex).at(i) -= log_total.log_ans;
                    log_sum.addPositiveLogPoint(_log_c.at(d).at(pIndex).at(i));
                }
            }
            if(log_sum.needToInitialize || !logCompare(log_sum.log_ans,0.0)) {
            // if(log_sum.needToInitialize || abs(log_sum.log_ans-0.0) > LOG_PRECISION) {
                cout << "Failed at line: " << __LINE__ << endl;
                cout << "log_sum.log_ans was: " << log_sum.log_ans << endl;                
                raise(SIGABRT);
            }
        }
        ++d;
    }
}


void EMPedigreeOptimizer::_log_dUpdate() {

    int d = 0;
    for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {

        pedigreeClass2* pedigree = *ped_it;

        for(int f=0; f<pedigree->families.size(); ++f) {

            vector<personClass*> family = pedigree->families.at(f);
            personClass* mother = family.at(0);
            personClass* father = family.at(1);
            int motherN = mother->n;
            int fatherN = father->n;
            int mIndex = pedigree->mapToIndexAllPeople.at(mother);
            int fIndex = pedigree->mapToIndexAllPeople.at(father);

            logAddition log_total;
            for(int i=0; i<motherN; ++i) {

                double log_a_i_pq = _getLogAVal(pedigree,d,f,true,i);
                for(int j=0; j<fatherN; ++j) {

                    double log_w_ij_qp = _getLogWVal(pedigree,d,f,true,i,j);
                    if(log_a_i_pq == UNIQUE_ZERO_ID || log_w_ij_qp == UNIQUE_ZERO_ID) {
                        _log_d.at(d).at(f).at(i).at(j) = UNIQUE_ZERO_ID;
                    }
                    else {
                        double log_val = log_a_i_pq + log_w_ij_qp;
                        _log_d.at(d).at(f).at(i).at(j) = log_val;
                        log_total.addPositiveLogPoint(log_val);
                    }
                }
            }

            vector<logAddition> log_sums(fatherN);
            for(int i=0; i<motherN; ++i) {

                logAddition log_marginalizeSum;
                for(int j=0; j<fatherN; ++j) {

                    if(log_total.needToInitialize == false && _log_d.at(d).at(f).at(i).at(j) != UNIQUE_ZERO_ID) {

                        _log_d.at(d).at(f).at(i).at(j) -= log_total.log_ans;
                        double log_val = _log_d.at(d).at(f).at(i).at(j);
                        log_marginalizeSum.addPositiveLogPoint(log_val);
                        log_sums.at(j).addPositiveLogPoint(log_val);
                    }
                }
                double log_compareAgainst = _log_c.at(d).at(mIndex).at(i);
                if(!(log_marginalizeSum.needToInitialize && log_compareAgainst == UNIQUE_ZERO_ID) && !logCompare(log_marginalizeSum.log_ans,log_compareAgainst)) {
                // if(!(log_marginalizeSum.needToInitialize && log_compareAgainst == UNIQUE_ZERO_ID) && (abs(log_marginalizeSum.log_ans - log_compareAgainst) > LOG_PRECISION)) {
                    cout << "Failed at line: " << __LINE__ << endl;
                    cout << "log_marginalizeSum.log_ans was: " << log_marginalizeSum.log_ans << " and log_compareAgainst was: " << log_compareAgainst << endl;
                    raise(SIGABRT);
                }
            }
            for(int j=0; j<fatherN; ++j) {

                double log_marginalizeSum;
                if(log_sums.at(j).needToInitialize) {
                    log_marginalizeSum = UNIQUE_ZERO_ID;
                }
                else {
                    log_marginalizeSum = log_sums.at(j).log_ans;
                }
                double log_compareAgainst = _log_c.at(d).at(fIndex).at(j);
                if(!(log_marginalizeSum == UNIQUE_ZERO_ID && log_compareAgainst == UNIQUE_ZERO_ID) && !logCompare(log_marginalizeSum, log_compareAgainst)) {
                // if(!(log_marginalizeSum == UNIQUE_ZERO_ID && log_compareAgainst == UNIQUE_ZERO_ID) && (abs(log_marginalizeSum - log_compareAgainst) > LOG_PRECISION)) {
                    cout << "Failed at line: " << __LINE__ << endl;
                    cout << "log_marginalizeSum was: " << log_marginalizeSum << " and log_compareAgainst was: " << log_compareAgainst << endl;
                    raise(SIGABRT);
                }
            }
        }
        ++d;
    }
}

void EMPedigreeOptimizer::_log_eUpdate() {

    int d = 0;
    for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {

        pedigreeClass2* pedigree = *ped_it;

        for(int f=0; f<pedigree->families.size(); ++f) {

            vector<personClass*> family = pedigree->families.at(f);
            personClass* mother = family.at(0);
            personClass* father = family.at(1);
            int motherN = mother->n;
            int fatherN = father->n;


            for(int c=0; c<family.size()-2; ++c) {

                personClass* child = family.at(c+2);
                int childN = child->n;
                int sexIndex = getSexIndex(pedigree,child);
                int shadingIndex = _emissionMapping.at(child->typeOfShading);
                int motherIsP = (int)(child->sex=="female");

                logAddition log_total;
                for(int i=0; i<motherN; ++i) {

                    double log_a_i_pq = _getLogAVal(pedigree,d,f,true,i);
                    for(int j=0; j<fatherN; ++j) {

                        double log_a_j_qp = _getLogAVal(pedigree,d,f,false,j);

                        double log_bProd = 0.0;
                        double log_bProdTotal = 0.0;
                        for(int s=0; s<family.size()-2; ++s) {
                            
                            personClass* sibling = family.at(s+2);
                            double log_b_ij_s = _getLogBVal(pedigree,d,f,i,j,sibling,s);

                            if(log_b_ij_s == UNIQUE_ZERO_ID) {
                                log_bProdTotal = UNIQUE_ZERO_ID;
                                log_bProd = UNIQUE_ZERO_ID;
                                break;
                            }

                            log_bProdTotal += log_b_ij_s;
                            if(s == c) {
                                continue;
                            }
                            log_bProd += log_b_ij_s;
                        }

                        logAddition log_shouldEqual_b_ij_c;
                        for(int k=0; k<childN; ++k) {

                            double A_ijk = _transitionProbs.at(sexIndex).at(i).at(j).at(k);
                            double B_k_c = _emissionProbs.at(sexIndex).at(k).at(shadingIndex);
                            double log_mProd = 0.0;
                            for(auto pair_it=child->mateKids.begin(); pair_it!=child->mateKids.end(); ++pair_it) {

                                personClass* mate = pair_it->first;
                                int mateN = mate->n;
                                personClass* mother_;
                                personClass* father_;
                                sortMates(child,mate,mother_,father_);
                                int newF = getFamNumb(pedigree,mother_,father_);

                                logAddition log_kSum;
                                for(int k_=0; k_<mateN; ++k_) {

                                    double log_w_kk__mc;
                                    log_w_kk__mc = _getLogWVal(pedigree,d,newF,motherIsP,k,k_);
                                     // cout << "newF: " << newF << " | k: " << k << " | _k: " << k_ << " | val: " << log_w_kk__mc << endl;
                                    if(log_w_kk__mc == UNIQUE_ZERO_ID) {
                                        continue;
                                    }
                                    log_kSum.addPositiveLogPoint(log_w_kk__mc);
                                }
                                 // cout << "newF: " << newF << " | sum: " << log_kSum.log_ans << endl;
                                if(log_kSum.needToInitialize || log_mProd == UNIQUE_ZERO_ID) {
                                    log_mProd = UNIQUE_ZERO_ID;
                                }
                                else {
                                    log_mProd += log_kSum.log_ans;
                                }
                            }

                            if(log_a_i_pq == UNIQUE_ZERO_ID || log_a_j_qp == UNIQUE_ZERO_ID || A_ijk == 0 || B_k_c == 0 || log_mProd == UNIQUE_ZERO_ID || log_bProd == UNIQUE_ZERO_ID) {
                                _log_e.at(d).at(f).at(i).at(j).at(c).at(sexIndex).at(k) = UNIQUE_ZERO_ID;
                            }
                            else {
                                double log_val = log_a_i_pq + log_a_j_qp + log(A_ijk) + log(B_k_c) + log_mProd + log_bProd;
                                _log_e.at(d).at(f).at(i).at(j).at(c).at(sexIndex).at(k) = log_val;
                                log_total.addPositiveLogPoint(log_val);
                            }
                            
                            
                            if(A_ijk != 0 && B_k_c != 0 && log_mProd != UNIQUE_ZERO_ID) {

                                double log_combined = log(A_ijk) + log(B_k_c) + log_mProd;
                                 // cout << "newC: " << c << " | A_ijk: " << A_ijk << endl;
                                 // cout << "newC: " << c << " | B_k_c: " << B_k_c << endl;
                                 // cout << "newC: " << c << " | log_mProd: " << log_mProd << endl;
                                 // cout << "newC: " << c << " | val: " << log_combined << endl;
                                log_shouldEqual_b_ij_c.addPositiveLogPoint(log_combined);
                            }

                        }
                        
                        ///////////////////////
                        double log_real_b_ij_c = _getLogBVal(pedigree,d,f,i,j,child,c);
                        if(!logCompare(log_shouldEqual_b_ij_c.log_ans, log_real_b_ij_c) && log_real_b_ij_c != UNIQUE_ZERO_ID && log_shouldEqual_b_ij_c.needToInitialize == false) {
                        // if(abs(log_shouldEqual_b_ij_c.log_ans - log_real_b_ij_c) > LOG_PRECISION && log_real_b_ij_c != UNIQUE_ZERO_ID &&log_shouldEqual_b_ij_c.needToInitialize == false) {
                            cout << "Failed at line: " << __LINE__ << endl;  
                            cout << "log_shouldEqual_b_ij_c.log_ans was: " << log_shouldEqual_b_ij_c.log_ans << " and log_real_b_ij_c was: " << log_real_b_ij_c << endl;
                            raise(SIGABRT);
                        }
                        ///////////////////////

                        double log_shouldEqual_totalBProd;
                        if(log_bProd == UNIQUE_ZERO_ID || log_shouldEqual_b_ij_c.needToInitialize) {
                            log_shouldEqual_totalBProd = UNIQUE_ZERO_ID;
                        }
                        else {
                            log_shouldEqual_totalBProd = log_bProd + log_shouldEqual_b_ij_c.log_ans;
                        }
                        if(!logCompare(log_shouldEqual_totalBProd, log_bProdTotal)) {
                        // if(abs(log_shouldEqual_totalBProd - log_bProdTotal) > LOG_PRECISION) {
                            cout << "Failed at line: " << __LINE__ << endl;  
                            cout << "log_shouldEqual_totalBProd was: " << log_shouldEqual_totalBProd << " and log_bProdTotal was: " << log_bProdTotal << endl;
                            raise(SIGABRT);
                        }

///////////////////////
                        double shouldEqual_w_ij_qp;
                        if(log_a_j_qp == UNIQUE_ZERO_ID || log_bProd == UNIQUE_ZERO_ID || log_shouldEqual_b_ij_c.needToInitialize) {
                            shouldEqual_w_ij_qp = UNIQUE_ZERO_ID;
                        }
                        else {
                            shouldEqual_w_ij_qp = log_a_j_qp + log_bProd + log_shouldEqual_b_ij_c.log_ans;
                        }
                        double log_w_real = _getLogWVal(pedigree,d,f,true,i,j);
                        if(!logCompare(shouldEqual_w_ij_qp, log_w_real)) {
                        // if(abs(shouldEqual_w_ij_qp - log_w_real) > LOG_PRECISION) {
                            cout << "Failed at line: " << __LINE__ << endl;  
                            cout << "shouldEqual_w_ij_qp was: " << shouldEqual_w_ij_qp << " and log_w_real was: " << log_w_real << endl;
                            raise(SIGABRT);
                        }
///////////////////////
                    }
                }
                for(int i=0; i<motherN; ++i) {
                    for(int j=0; j<fatherN; ++j) {
                        logAddition log_marginalizeSum;
                        for(int k=0; k<childN; ++k) {
                            if(_log_e.at(d).at(f).at(i).at(j).at(c).at(sexIndex).at(k) == UNIQUE_ZERO_ID) {
                                continue;
                            }
                            if(log_total.needToInitialize) {
                                cout << "Failed at line: " << __LINE__ << endl;  
                                cout << "DIVIDE BY ZERO!!" << endl;
                                raise(SIGABRT);
                            }
                            _log_e.at(d).at(f).at(i).at(j).at(c).at(sexIndex).at(k) -= log_total.log_ans;
                            log_marginalizeSum.addPositiveLogPoint(_log_e.at(d).at(f).at(i).at(j).at(c).at(sexIndex).at(k));
                        }
                        double log_compareAgainst = _log_d.at(d).at(f).at(i).at(j);
                        if(!logCompare(log_marginalizeSum.log_ans, log_compareAgainst) && !(log_compareAgainst == UNIQUE_ZERO_ID && log_marginalizeSum.needToInitialize)) {
                        // if(abs(log_marginalizeSum.log_ans - log_compareAgainst) > LOG_PRECISION && !(log_compareAgainst == UNIQUE_ZERO_ID && log_marginalizeSum.needToInitialize)) {
                            cout << "Failed at line: " << __LINE__ << endl;
                            cout << "log_marginalizeSum.log_ans was: " << log_marginalizeSum.log_ans << " and log_compareAgainst was: " << log_compareAgainst << endl;
                            raise(SIGABRT);
                        }
                    }
                }
            }
        }
        ++d;
    }
}



void EMPedigreeOptimizer::_log_updateRootProbs2() {
    int d = 0;
    for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {
        
        int r = 0;
        for(auto r_it=(*ped_it)->roots.begin(); r_it!=(*ped_it)->roots.end(); ++r_it) {
            
            personClass* root = *r_it;
            int rootN = root->n;
            int rIndex = (*ped_it)->mapToIndexAllPeople.at(root);
            
            double totalSum = 0.0;
            for(int i=0; i<rootN; ++i) {
                double val = _log_c.at(d).at(rIndex).at(i);
                double expVal;
                if(val == UNIQUE_ZERO_ID) {
                    expVal = 0.0;
                }
                else {
                    expVal = exp(val);
                }
                totalSum += expVal;
                _rootProbs.at(d).at(r).at(i) = expVal;
            }
            ++r;
            
            
            if(abs(totalSum-1.0) > PRECISION) {
                cout << "Failed at line: " << __LINE__ << endl;
                cout << "Total sum was: " << totalSum << endl;
                raise(SIGABRT);
            }
        }
        ++d;
    }
}

void EMPedigreeOptimizer::_log_updateTransitionProbs2() {
    
    vector<int> sexToIterate;
    if(_sexDependent) {
        sexToIterate = vector<int>({_femaleN,_maleN,_unknownN});
    }
    else {
        sexToIterate = vector<int>({_femaleN});
    }
    
    
    for(int i=0; i<_femaleN; ++i) {
        for(int j=0; j<_maleN; ++j) {
            

            vector<vector<logAddition>> vals(sexToIterate.size());
            for(int s=0; s<vals.size(); ++s) {
                vals.at(s) = vector<logAddition>(_transitionProbs.at(s).at(i).at(j).size());
            }

            logAddition log_denominator;
            
            int d = 0;
            for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {
                
                for(int f=0; f<(*ped_it)->families.size(); ++f) {
                    
                    vector<personClass*> currentFam = (*ped_it)->families.at(f);
                    
                    for(int c=0; c<currentFam.size()-2; ++c) {
                        
                        double log_delta_ij_f = _log_d.at(d).at(f).at(i).at(j);
                        if(log_delta_ij_f != UNIQUE_ZERO_ID) {
                            log_denominator.addPositiveLogPoint(log_delta_ij_f);
                        }
                        
                        personClass* child = currentFam.at(c+2);
                        int childN = child->n;
                        int sexOfChild = getSexIndex(*ped_it,child);
                        
                        for(int k=0; k<childN; ++k) {
                            double log_zeta_ijk_f = _log_e.at(d).at(f).at(i).at(j).at(c).at(sexOfChild).at(k);
                            if(log_zeta_ijk_f != UNIQUE_ZERO_ID) {
                                vals.at(sexOfChild).at(k).addPositiveLogPoint(log_zeta_ijk_f);
                            }
                        }
                    }
                }
                ++d;
            }
            
            double total = 0.0;
            for(int s=0; s<_transitionProbs.size(); ++s) {
                for(int k=0; k<_transitionProbs.at(s).at(i).at(j).size(); ++k) {
                    double expVal;
                    if(vals.at(s).at(k).needToInitialize) {
                        expVal = 0.0;
                    }
                    else {
                        if(log_denominator.needToInitialize) {
                            cout << "Failed at line: " << __LINE__ << endl;
                            cout << "Dividing by zero!" << endl;
                            raise(SIGABRT);
                        }
                        double val = vals.at(s).at(k).log_ans - log_denominator.log_ans;
                        expVal = exp(val);
                    }
                    _transitionProbs.at(s).at(i).at(j).at(k) = expVal;
                    total += expVal;
                }
            }
            if(abs(total-1.0) > pow(10,-10)) {
//                cout << "Failed at line: " << __LINE__ << endl;
//                cout << "Total was: " << total << endl;
//                raise(SIGABRT);
            }
        }
    }
}

void EMPedigreeOptimizer::_log_updateEmissionProbs2() {
    
    vector<int> sexToIterate;
    if(_sexDependent) {
        sexToIterate = vector<int>({_femaleN,_maleN,_unknownN});
    }
    else {
        sexToIterate = vector<int>({_femaleN});
    }
    
    for(int sex=0; sex<sexToIterate.size(); ++sex) {
        
        int sexN = sexToIterate.at(sex);
        
        for(int i=0; i<sexN; ++i) {
            
            // emission possibilities
            double sum = 0.0;
            for(int y=0; y<4; ++y) {
                
                logAddition log_val;
                logAddition log_denominator;
                
                int d = 0;
                for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {
                    
                    for(auto p_it=(*ped_it)->allPeople.begin(); p_it!=(*ped_it)->allPeople.end(); ++p_it) {
                        
                        personClass* current = *p_it;
                        int pIndex = (*ped_it)->mapToIndexAllPeople.at(current);
                        int sexInner = getSexIndex(*ped_it,current);
                        int shadingIndex = _emissionMapping.at(current->typeOfShading);
                        
                        if(sex != sexInner) {
                            continue;
                        }
                        
                        double log_epsilon_i_p = _log_c.at(d).at(pIndex).at(i);
                        if(log_epsilon_i_p == UNIQUE_ZERO_ID) {
                            continue;
                        }
                        log_denominator.addPositiveLogPoint(log_epsilon_i_p);
                        
                        if(shadingIndex == y) {
                            log_val.addPositiveLogPoint(log_epsilon_i_p);
                        }
                    }
                    ++d;
                }
                double expVal;
                if(log_val.needToInitialize) {
                    expVal = 0;
                }
                else {
                    if(log_denominator.needToInitialize) {
                        cout << "Failed at line: " << __LINE__ << endl;
                        cout << "Divided by zero!" << endl;
                        raise(SIGABRT);
                    }
                    double val = log_val.log_ans - log_denominator.log_ans;
                    expVal = exp(val);
                }

                _emissionProbs.at(sex).at(i).at(y) = expVal;
                sum += expVal;
            }
            if(abs(sum-1.0) > PRECISION) {
                cout << "Failed at line: " << __LINE__ << endl;
                cout << "Sum was: " << sum << endl;
                raise(SIGABRT);
            }
        }
    }
}


void EMPedigreeOptimizer::_log_eStep2() {
    _log_cUpdate();
    _log_dUpdate();
    _log_eUpdate();
}

void EMPedigreeOptimizer::_log_mStep2() {
    _log_updateRootProbs2();
    _log_updateEmissionProbs2();
    _log_updateTransitionProbs2();
}

void EMPedigreeOptimizer::_log_EMStep2() {
    _resetDataStructures();
    _log_eStep2();
    _log_mStep2();
}


double EMPedigreeOptimizer::_calculateProbability(pedigreeClass2* pedigree, vector<vector<vector<double>>> rootProbs) {

    double log_ans = 0.0;

    return 0.0;
}














