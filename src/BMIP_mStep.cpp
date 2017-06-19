#include "BMIP.h"


void EMPedigreeOptimizer::_log_updateRootProbs2() {
    int d = 0;
    for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {
        
        pedigreeClass2* pedigree = *ped_it;

        int r = 0;
        for(auto r_it=(*ped_it)->roots.begin(); r_it!=(*ped_it)->roots.end(); ++r_it) {
            
            personClass* root = *r_it;
            int rootN = _getN(root);
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
                cout << "Pedigree filename: " << pedigree->filename << endl;
                cout << "Person id is: " << root->_id << endl;

                totalSum = 0.0;
                cout << "_log_c vals: ";
                for(int i=0; i<rootN; ++i) {
                    double val = _log_c.at(d).at(rIndex).at(i);
                    cout << val << " ";
                }
                cout << endl;

                raise(SIGABRT);
            }
        }
        ++d;
    }
}

void EMPedigreeOptimizer::_log_updateTransitionProbs2() {

    for(int s=0; s<_transitionProbs.size(); ++s) {
        for(int i=0; i<_femaleN; ++i) {
            for(int j=0; j<_maleN; ++j) {
                
                int N;
                if(s == 0) {
                    N = _femaleN;
                }
                else if(s == 1) {
                    N = _maleN;
                }
                else if(s == 2) {
                    N = _unknownN;
                }
                else {
                    cout << "Failed at line: " << __LINE__ << endl;
                    cout << "Not ready for this" << endl;
                    raise(SIGABRT);
                }

                logAddition log_total;
                vector<logAddition> log_vals(N);
                
                for(int k=0; k<N; ++k) {
                    
                    int d = 0;
                    for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {
                        
                        for(int f=0; f<(*ped_it)->families.size(); ++f) {
                            
                            vector<personClass*> currentFam = (*ped_it)->families.at(f);
                            
                            for(int c=0; c<currentFam.size()-2; ++c) {
                                
                                personClass* child = currentFam.at(c+2);
                                int sexOfChild = _getSexIndex(child);

                                if(sexOfChild != s) {
                                    continue;
                                }
                                
                                double log_zeta_ijk_f = _log_e.at(d).at(f).at(i).at(j).at(c).at(sexOfChild).at(k);
                                if(log_zeta_ijk_f != UNIQUE_ZERO_ID) {
                                    log_vals.at(k).addPositiveLogPoint(log_zeta_ijk_f);
                                    log_total.addPositiveLogPoint(log_zeta_ijk_f);
                                }
                            }
                        }
                        ++d;
                    }   
                }

                if(log_total.needToInitialize) {
                    // this means that there is no way, given the current configuration of
                    // the parameters, to get a transition from (i,j)->k for sex s.
                    continue;
                }

                
                double total = 0.0;
                for(int k=0; k<N; ++k) {

                    double val = 0.0;
                    logAddition log_numerator = log_vals.at(k);

                    if(!log_numerator.needToInitialize) {
                        double log_val = log_numerator.log_ans - log_total.log_ans;
                        val = exp(log_val);
                    }
                    _transitionProbs.at(s).at(i).at(j).at(k) = val;
                    total += val;
                }  
                if(abs(total-1.0) > PRECISION) {
                    cout << "Failed at line: " << __LINE__ << endl;
                    raise(SIGABRT);
                }     
            }
        }
    }
}


void EMPedigreeOptimizer::_log_updateEmissionProbs2() {

    for(int sex=0; sex<_nSexIndices; ++sex) {
        
        string sexString = _sexOrder.at(sex);
        int sexN = _getN(sexString);
        
        for(int i=0; i<sexN; ++i) {
            
            // emission possibilities
            double sum = 0.0;
            for(int y=0; y<_emissionMapping.size(); ++y) {
                
                logAddition log_val;
                logAddition log_denominator;
                
                int d = 0;
                for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {
                    
                    for(auto p_it=(*ped_it)->allPeople.begin(); p_it!=(*ped_it)->allPeople.end(); ++p_it) {
                        
                        personClass* current = *p_it;
                        int pIndex = (*ped_it)->mapToIndexAllPeople.at(current);
                        int sexInner = _getSexIndex(current);
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
            if(abs(sum-0.0) < PRECISION) {
                // then there are no examples, so set to
                // uniform random
                sum = 0.0;
                for(int y=0; y<_emissionMapping.size(); ++y) {
                    double val = 1.0/(double)_emissionMapping.size();
                    _emissionProbs.at(sex).at(i).at(y) = val;
                    sum += val;
                }
            }
            if(abs(sum-1.0) > PRECISION) {
                cout << "Failed at line: " << __LINE__ << endl;
                cout << "Sum was: " << sum << endl;
                raise(SIGABRT);
            }
        }
    }
}

void EMPedigreeOptimizer::_log_mStep2(bool rootProbUpdate, bool emissionProbUpdate, bool transitionProbUpdate) {

    if(rootProbUpdate) {
        _log_updateRootProbs2();
    }
    if(emissionProbUpdate) {
        _log_updateEmissionProbs2();
    }
    if(transitionProbUpdate) {
        _log_updateTransitionProbs2();
    }
}


