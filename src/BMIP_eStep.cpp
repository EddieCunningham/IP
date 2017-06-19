#include "BMIP.h"
#define PRINT_VALS false

// _u -> [pedigree (d)][person (c)][chromosome (k)] -> u_k(c)
double EMPedigreeOptimizer::_getLogUVal(pedigreeClass2* pedigree, int d, personClass* child, int k) {

    int c = pedigree->mapToIndexAllPeople.at(child);

    pair<int,double> spot = _log_u.at(d).at(c).at(k);
    int status = spot.first;
    if(status == 0) {

        ++_nTabs;
        _computeLogUVal(pedigree,d,child,k);
        --_nTabs;

        if(PRINT_VALS) {
            for(int it=0; it<_nTabs; ++it) {cout << "\t";}
            cout << "Just computed u{" << endl;
            for(int it=0; it<_nTabs; ++it) {cout << "\t";}
            cout << "\td: " << d << ", child: " << child->_id << ", k: " << k << endl;
            for(int it=0; it<_nTabs; ++it) {cout << "\t";}
            cout << "} is: " << _log_u.at(d).at(c).at(k).second << endl << endl;
        }
    }
    else if(status == 2) {
        cout << "Failed at line: " << __LINE__ << endl;
        cout << "ALREADY COMPUTING VALUE" << endl;
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
        ++_nTabs;
        _computeLogWVal(pedigree,d,f,motherIsP,i,j);
        --_nTabs;

        vector<personClass*> fam = pedigree->families.at(f);
        int motherId = fam.at(0)->_id;
        int fatherId = fam.at(1)->_id;

        if(PRINT_VALS) {
            for(int it=0; it<_nTabs; ++it) {cout << "\t";}
            cout << "Just computed w{" << endl;
            for(int it=0; it<_nTabs; ++it) {cout << "\t";}
            cout << "\td: " << d << ", f: (" << motherId << "," << fatherId << "), motherIsP: " << motherIsP << ", i: " << i << ", j: " << j << endl;
            for(int it=0; it<_nTabs; ++it) {cout << "\t";}
            cout << "} is: " << _log_w.at(d).at(f).at(motherIsP).at(i).at(j).second << endl << endl;
        }
    }
    else if(status == 2) {
        cout << "Failed at line: " << __LINE__ << endl;
        cout << "ALREADY COMPUTING VALUE" << endl;
        raise(SIGABRT);
    }
    else if(status == 3) {
        return UNIQUE_ZERO_ID;
    }
    double wVal = _log_w.at(d).at(f).at(motherIsP).at(i).at(j).second;
    return wVal;
}

// _a -> [pedigree (d)][familyUnit (f)][p==mother][parentAChromosome (i)] -> a_i(p,q)
double EMPedigreeOptimizer::_getLogAVal(pedigreeClass2* pedigree, int d, int f, int motherIsP, int i) {

    pair<int,double> spot = _log_a.at(d).at(f).at(motherIsP).at(i);
    int status = spot.first;
    if(status == 0) {
        ++_nTabs;
        _computeLogAVal(pedigree,d,f,motherIsP,i);
        --_nTabs;

        vector<personClass*> fam = pedigree->families.at(f);
        int motherId = fam.at(0)->_id;
        int fatherId = fam.at(1)->_id;

        if(PRINT_VALS) {
            for(int it=0; it<_nTabs; ++it) {cout << "\t";}
            cout << "Just computed a{" << endl;
            for(int it=0; it<_nTabs; ++it) {cout << "\t";}
            cout << "\td: " << d << ", f: (" << motherId << "," << fatherId << "), motherIsP: " << motherIsP << ", i: " << i << endl;
            for(int it=0; it<_nTabs; ++it) {cout << "\t";}
            cout << "} is: " << _log_a.at(d).at(f).at(motherIsP).at(i).second << endl << endl;
        }
    }
    else if(status == 2) {
        cout << "Failed at line: " << __LINE__ << endl;
        cout << "ALREADY COMPUTING VALUE" << endl;
        raise(SIGABRT);
    }
    else if(status == 3) {
        return UNIQUE_ZERO_ID;
    }
    double aVal = _log_a.at(d).at(f).at(motherIsP).at(i).second;
    return aVal;
}

// _b -> [pedigree (d)][familyUnit (f)][motherChromosome (i)][fatherChromosome (j)][childNumber (c)][childSexIndex] -> b_ij(c)
double EMPedigreeOptimizer::_getLogBVal(pedigreeClass2* pedigree, int d, int f, int i, int j, personClass* child, int c) {
    
    int sexIndex = _getSexIndex(pedigree,child);
    pair<int,double> spot = _log_b.at(d).at(f).at(i).at(j).at(c).at(sexIndex);
    int status = spot.first;
    if(status == 0) {
        ++_nTabs;
        _computeLogBVal(pedigree,d,f,i,j,child,c);
        --_nTabs;

        vector<personClass*> fam = pedigree->families.at(f);
        int motherId = fam.at(0)->_id;
        int fatherId = fam.at(1)->_id;

        if(PRINT_VALS) {
            for(int it=0; it<_nTabs; ++it) {cout << "\t";}
            cout << "Just computed b{" << endl;
            for(int it=0; it<_nTabs; ++it) {cout << "\t";}
            cout << "\td: " << d << ", f: (" << motherId << "," << fatherId << "), i: " << i << ", j: " << j << ", child: " << child->_id << ", c: " << c << endl;
            for(int it=0; it<_nTabs; ++it) {cout << "\t";}
            cout << "} is: " << _log_b.at(d).at(f).at(i).at(j).at(c).at(sexIndex).second << endl << endl;
        }
    }
    else if(status == 2) {
        cout << "Failed at line: " << __LINE__ << endl;
        cout << "ALREADY COMPUTING VALUE" << endl;
        raise(SIGABRT);
    }
    else if(status == 3) {
        return UNIQUE_ZERO_ID;
    }
    double bVal = _log_b.at(d).at(f).at(i).at(j).at(c).at(sexIndex).second;
    return bVal;

}

// _a -> [pedigree (d)][familyUnit (f)][p==mother][parentAChromosome (i)] -> a_i(p,q)
void EMPedigreeOptimizer::_computeLogAVal(pedigreeClass2* pedigree, int d, int f, int motherIsP, int i) {

    if(_log_a.at(d).at(f).at(motherIsP).at(i).first == 1 || _log_a.at(d).at(f).at(motherIsP).at(i).first == 3) {
        return;
    }
    else if(_log_a.at(d).at(f).at(motherIsP).at(i).first == 2) {
        cout << "Failed at line: " << __LINE__ << endl;
        cout << "can't happen" << endl;
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
        int newF = _getFamNumb(pedigree,p,mate);

        logAddition sum;

        for(int i_=0; i_<mateN; ++i_) {

            double log_w_ii__mp = _getLogWVal(pedigree,d,newF,motherIsP,i,i_);
            _safeAdd(sum,log_w_ii__mp);
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

    int sexIndex = _getSexIndex(pedigree,child);

    if(_log_b.at(d).at(f).at(i).at(j).at(c).at(sexIndex).first == 1 || _log_b.at(d).at(f).at(i).at(j).at(c).at(sexIndex).first == 3) {
        return;
    }
    else if(_log_b.at(d).at(f).at(i).at(j).at(c).at(sexIndex).first == 2) {
        cout << "Failed at line: " << __LINE__ << endl;
        raise(SIGABRT);
    }

    _log_b.at(d).at(f).at(i).at(j).at(c).at(sexIndex).first = 2;

    // int shadingIndex = _emissionMapping.at(child->typeOfShading);
    int childN = child->n;
    int motherIsP = (int)(child->sex=="female");

    logAddition log_val;

    for(int k=0; k<childN; ++k) {

        double A_ijk = _getTransitionProb(pedigree,child,i,j,k);
        double bVal = _getEmissionProb(pedigree,child,k);

        double log_cProd = 0.0;
        bool allZeroFlag = false;

        for(auto pair_it=child->mateKids.begin(); pair_it!=child->mateKids.end(); ++pair_it) {

            personClass* mate = pair_it->first;
            int mateN = mate->n;
            int newF = _getFamNumb(pedigree,child,mate);

            logAddition sum;
            for(int k_=0; k_<mateN; ++k_) {

                double log_w_kk__mc = _getLogWVal(pedigree,d,newF,motherIsP,k,k_);
                _safeAdd(sum,log_w_kk__mc);
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
        cout << "Failed at line: " << __LINE__ << endl;
        cout << "Can't be doing this!" << endl;
        raise(SIGABRT);
    }
    _log_u.at(d).at(cIndex).at(k).first = 2;

    double log_val = -1;
    if(child->parentA == nullptr) {

        double piVal = _getRootProb(pedigree,child,k);
        double bVal = _getEmissionProb(pedigree,child,k);
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
        _sortMates(child->parentA,child->parentB,mother,father);

        int motherN = mother->n;
        int fatherN = father->n;
        
        
        int f = _getFamNumb(pedigree,mother,father);
        const vector<personClass*>& family = pedigree->families.at(f);

        logAddition sum;
        for(int i=0; i<motherN; ++i) {

            double log_a_i_pq = _getLogAVal(pedigree,d,f,true,i);
            if(log_a_i_pq == UNIQUE_ZERO_ID) {
                continue;
            }
            for(int j=0; j<fatherN; ++j) {

                double A_ijk = _getTransitionProb(pedigree,child,i,j,k);
                double bVal = _getEmissionProb(pedigree,child,k);
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
        cout << "Failed at line: " << __LINE__ << endl;
        cout << "can't happen" << endl;
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

void EMPedigreeOptimizer::_log_cUpdate(double& log_PofY) {

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
                if(log_u_i_p == UNIQUE_ZERO_ID) {
                    _log_c.at(d).at(pIndex).at(i) = UNIQUE_ZERO_ID;
                    continue;
                }
                double log_mProd = 0.0;
                bool allZeroFlag = false;
                for(auto pair_it=person->mateKids.begin(); pair_it!=person->mateKids.end(); ++pair_it) {

                    personClass* mate = pair_it->first;
                    int mateN = mate->n;

                    personClass* mother;
                    personClass* father;
                    _sortMates(person,mate,mother,father);
                    int f = _getFamNumb(pedigree,mother,father);

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
                
                if(allZeroFlag) {
                    _log_c.at(d).at(pIndex).at(i) = UNIQUE_ZERO_ID;
                }
                else {
                    double log_val = log_u_i_p + log_mProd;
                    _log_c.at(d).at(pIndex).at(i) = log_val;
                    log_total.addPositiveLogPoint(log_val);
                }
            }
            
            if(log_total.needToInitialize) {
                cout << "Failed at line: " << __LINE__ << endl;
                cout << "log_total.needToInitialize: " << log_total.needToInitialize << endl;
                cout << "log_total.log_ans was: " << log_total.log_ans << endl;
                cout << "Person: " << person->_id << endl;
                cout << "log_c: ";
                for(int i=0; i<personN; ++i) {
                    cout << _log_c.at(d).at(pIndex).at(i) << " ";
                }
                cout << endl;
                
                
                cout << endl;
                raise(SIGABRT);
            }

            log_PofY = log_total.log_ans;

            logAddition log_sum;
            for(int i=0; i<personN; ++i) {
                if(log_total.needToInitialize == false && _log_c.at(d).at(pIndex).at(i) != UNIQUE_ZERO_ID) {
                    _log_c.at(d).at(pIndex).at(i) -= log_total.log_ans;
                    log_sum.addPositiveLogPoint(_log_c.at(d).at(pIndex).at(i));
                }
            }
            if(log_sum.needToInitialize || !_logCompare(log_sum.log_ans,0.0)) {
                cout << "Failed at line: " << __LINE__ << endl;
                raise(SIGABRT);
            }
        }
        ++d;
    }
}


void EMPedigreeOptimizer::_log_dUpdate(double& log_PofY) {

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

            if(!_logCompare(log_total.log_ans,log_PofY)) {
                if(f != 0) {
                    cout << "Failed at line: " << __LINE__ << endl;
                    cout << "This value shouldn't change!" << endl;
                    cout << "Changed from " << log_total.log_ans << " to " << log_PofY << endl;
                    raise(SIGABRT);
                }
                else {
                    log_PofY = log_total.log_ans;
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
                if(!(log_marginalizeSum.needToInitialize && log_compareAgainst == UNIQUE_ZERO_ID) && !_logCompare(log_marginalizeSum.log_ans,log_compareAgainst)) {
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
                if(!(log_marginalizeSum == UNIQUE_ZERO_ID && log_compareAgainst == UNIQUE_ZERO_ID) && !_logCompare(log_marginalizeSum, log_compareAgainst)) {
                    cout << "Failed at line: " << __LINE__ << endl;
                    cout << "log_marginalizeSum was: " << log_marginalizeSum << " and log_compareAgainst was: " << log_compareAgainst << endl;
                    raise(SIGABRT);
                }
            }
        }
        ++d;
    }
}

void EMPedigreeOptimizer::_log_eUpdate(double& log_PofY) {

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
                int sexIndex = _getSexIndex(pedigree,child);
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

                            double A_ijk = _getTransitionProb(pedigree,child,i,j,k);
                            double B_k_c = _getEmissionProb(pedigree,child,k);
                            double log_mProd = 0.0;
                            for(auto pair_it=child->mateKids.begin(); pair_it!=child->mateKids.end(); ++pair_it) {

                                personClass* mate = pair_it->first;
                                int mateN = mate->n;
                                personClass* mother_;
                                personClass* father_;
                                _sortMates(child,mate,mother_,father_);
                                int newF = _getFamNumb(pedigree,mother_,father_);

                                logAddition log_kSum;
                                for(int k_=0; k_<mateN; ++k_) {

                                    double log_w_kk__mc;
                                    log_w_kk__mc = _getLogWVal(pedigree,d,newF,motherIsP,k,k_);
                                    if(log_w_kk__mc == UNIQUE_ZERO_ID) {
                                        continue;
                                    }
                                    log_kSum.addPositiveLogPoint(log_w_kk__mc);
                                }
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
                                log_shouldEqual_b_ij_c.addPositiveLogPoint(log_combined);
                            }

                        }
                        
                        ///////////////////////
                        double log_real_b_ij_c = _getLogBVal(pedigree,d,f,i,j,child,c);
                        if(!_logCompare(log_shouldEqual_b_ij_c.log_ans, log_real_b_ij_c) && log_real_b_ij_c != UNIQUE_ZERO_ID && log_shouldEqual_b_ij_c.needToInitialize == false) {
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
                        if(!_logCompare(log_shouldEqual_totalBProd, log_bProdTotal)) {
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
                        if(!_logCompare(shouldEqual_w_ij_qp, log_w_real)) {
                            cout << "Failed at line: " << __LINE__ << endl;  
                            cout << "shouldEqual_w_ij_qp was: " << shouldEqual_w_ij_qp << " and log_w_real was: " << log_w_real << endl;
                            raise(SIGABRT);
                        }
///////////////////////
                    }
                }

                if(!_logCompare(log_total.log_ans,log_PofY)) {
                    if(f != 0) {
                        cout << "Failed at line: " << __LINE__ << endl; 
                        cout << "This value shouldn't change!" << endl;
                        raise(SIGABRT);
                    }
                    else {
                        log_PofY = log_total.log_ans;
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
                        if(!_logCompare(log_marginalizeSum.log_ans, log_compareAgainst) && !(log_compareAgainst == UNIQUE_ZERO_ID && log_marginalizeSum.needToInitialize)) {
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

void EMPedigreeOptimizer::_log_eStep2(double& log_PofY) {
    _log_cUpdate(log_PofY);
    _log_dUpdate(log_PofY);
    _log_eUpdate(log_PofY);
}


