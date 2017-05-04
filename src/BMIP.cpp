#include "BMIP.h"
/*



LOOK AT PREVIOUS GROUPS WORK

use these words in a sentence to send to dana
- numerical method
- hidden markov model
- stochastic method


*/



void EMPedigreeOptimizer::initialize(const vector<pedigreeClass2*> & trainingSet_, bool printPeople) {

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
            cout << "NEED SAME SEX DEPENDENCY!!" << endl;
            raise(SIGABRT);
        }
        
        for(auto p_it=(*ped_it)->allPeople.begin(); p_it!=(*ped_it)->allPeople.end(); ++p_it) {

            if((*p_it)->parentA && (*p_it)->parentA->sex == "unknown") {
                cout << "DONT SUPPORT THIS CASE YET" << endl;
                raise(SIGABRT);
            }

            string sex = (*p_it)->sex;
            int n = (*p_it)->n;

            if(sex == "male") {
                if(maleN != -1) {
                    if(maleN != n) {
                        cout << "INCONSISTENT " << maleN << endl;
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
                        cout << "INCONSISTENT " << femaleN << endl;
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
                        cout << "INCONSISTENT " << unknownN << endl;
                        raise(SIGABRT);
                    }
                }
                else {
                    unknownN = n;
                }
            }
            else {
                cout << "INVALID SEX!!" << endl;
                raise(SIGABRT);
            }
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
        toPrint += "empo.initialize(trainingSet,false);";
        cout << toPrint;
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
            for(int i=0; i<n; ++i) {
                double randomNumb = rand()/(double)RAND_MAX;
                rootToAdd.at(i) = randomNumb;
            }
            rootsToAdd.push_back(rootToAdd);
            
        }
        _rootProbs.push_back(rootsToAdd);
    }

    int D = _trainingSet.size();
    _alpha = vector<vector<vector<double>>>();
    _beta = vector<vector<vector<vector<double>>>>();
    _gamma = vector<vector<vector<double>>>();
    _delta = vector<vector<vector<vector<double>>>>();
    _epsilon = vector<vector<vector<double>>>();
    _zeta = vector<vector<vector<vector<vector<vector<vector<double>>>>>>>();

/*
    _alpha -> [pedigree][person][chromosome]
    _beta -> [pedigree][familyUnit][chromosomeFemaleParent][chromosomeMaleParent]
    _gamma -> [pedigree][person][chromosome]
    _delta -> [pedigree][familyUnit][chromosomeFemaleParent][chromosomeMaleParent]
    _epsilon -> [pedigree][person][chromosome]
    _zeta -> [pedigree][familyUnit][chromosomeFemaleParent][chromosomeMaleParent][childNumber][childSex][childChromosome]
*/
    for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {

        vector<vector<double>> people = vector<vector<double>>();
        for(auto p_it=(*ped_it)->allPeople.begin(); p_it!=(*ped_it)->allPeople.end(); ++p_it) {

            int N = (*p_it)->n;
            vector<double> toAdd = vector<double>(N,0);
            people.push_back(toAdd);
        }
        _alpha.push_back(people);
        _gamma.push_back(people);
        _epsilon.push_back(people);

        int numFams = (*ped_it)->families.size();
        vector<vector<vector<vector<vector<vector<double>>>>>> zetaAddition = vector<vector<vector<vector<vector<vector<double>>>>>>(numFams,
                                                                                      vector<vector<vector<vector<vector<double>>>>>(femaleN,
                                                                                              vector<vector<vector<vector<double>>>>(maleN)));

        for(int f=0; f<(*ped_it)->families.size(); ++f) {

            int numbChildren = (*ped_it)->families.at(f).size()-2;
            vector<vector<vector<double>>> lastZetaPart;
            if(sexDependent) {
                lastZetaPart = vector<vector<vector<double>>>(numbChildren,
                                       vector<vector<double>>({ 
                                               vector<double>(femaleN),
                                               vector<double>(maleN),
                                               vector<double>(unknownN)}));
            }
            else {
                lastZetaPart = vector<vector<vector<double>>>(numbChildren,
                                       vector<vector<double>>(1,
                                               vector<double>(femaleN)));
            }

            for(int i=0; i<femaleN; ++i) {
                for(int j=0; j<maleN; ++j) {
                    zetaAddition.at(f).at(i).at(j) = lastZetaPart;
                }
            }
        }

        
        
        vector<vector<vector<double>>> betaDeltaAddition(numFams,
                                  vector<vector<double>>(femaleN,
                                          vector<double>(maleN)));


        _beta.push_back(betaDeltaAddition);
        _delta.push_back(betaDeltaAddition);
        _zeta.push_back(zetaAddition);
    }
}

int getSexIndex(pedigreeClass2* pedigree, personClass* person) {
    int sexIndex = 0;
    if(pedigree->sexDependent) {
        if(person->sex == "male") {
            sexIndex = 0;
        }
        else if(person->sex == "female") {
            sexIndex = 1;
        }
        else if(person->sex == "unknown") {
            sexIndex = 2;
        }
        else {
            cout << "Invalid sex" << endl;
            raise(SIGABRT);
        }
    }
    return sexIndex;
}


void sortMates(personClass* mateA, personClass* mateB, personClass*& femaleMate, personClass*& maleMate) {
    if(mateA->sex == "female") {
        femaleMate = mateA;
        maleMate = mateB;
    }
    else {
        maleMate = mateA;
        femaleMate = mateB;
    }
}

void EMPedigreeOptimizer::_alphaGammaRootCase(pedigreeClass2* pedigree, personClass* person, int N, int d, int pIndex, int sexIndex, int shadingIndex) {
    int rIndex = pedigree->mapToIndexRoots.at(person);

    // update the alpha values
    for(int k=0; k<N; ++k) {

        double piVal = _rootProbs.at(d).at(rIndex).at(k);
        double bVal = _emissionProbs.at(sexIndex).at(k).at(shadingIndex);
        _alpha.at(d).at(pIndex).at(k) = piVal*bVal;
        _gamma.at(d).at(pIndex).at(k) = piVal;
    }
}

void EMPedigreeOptimizer::_alphaGammaNormalCase(pedigreeClass2* pedigree, personClass* person, int N, int d, int pIndex, int sexIndex, int shadingIndex) {

    personClass* pA;
    personClass* pB;
    sortMates(person->parentA,person->parentB,pA,pB);

    int pAIndex = pedigree->mapToIndexAllPeople.at(pA);
    int pBIndex = pedigree->mapToIndexAllPeople.at(pB);

    for(int k=0; k<N; ++k) {

        _alpha.at(d).at(pIndex).at(k) = 0;
        _gamma.at(d).at(pIndex).at(k) = 0;

        for(int i=0; i<pA->n; ++i) {

            double alphaA = _alpha.at(d).at(pAIndex).at(i);
            double gammaA = _gamma.at(d).at(pAIndex).at(i);

            for(int j=0; j<pB->n; ++j) {

                double alphaB = _alpha.at(d).at(pBIndex).at(j);
                double gammaB = _gamma.at(d).at(pBIndex).at(j);
                double A_ijk = _transitionProbs.at(sexIndex).at(i).at(j).at(k);

                _alpha.at(d).at(pIndex).at(k) += A_ijk*alphaA*alphaB;
                _gamma.at(d).at(pIndex).at(k) += A_ijk*gammaA*gammaB;
            }
        }

        double bVal = _emissionProbs.at(sexIndex).at(k).at(shadingIndex);
        _alpha.at(d).at(pIndex).at(k) *= bVal;
    }

}  

void EMPedigreeOptimizer::_updateAlphaGamma() {

    int d = 0;
    for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {

        vector<personClass*> itSet = (*ped_it)->roots;

        while(itSet.size() > 0) {

            vector<personClass*> nextItSet = vector<personClass*>();

            for(auto p_it=itSet.begin(); p_it!=itSet.end(); ++p_it) {

                int pIndex = (*ped_it)->mapToIndexAllPeople.at(*p_it);
                int shadingIndex = _emissionMapping.at((*p_it)->typeOfShading);
                int sexIndex = getSexIndex(*ped_it,*p_it);                

                int N = (*p_it)->n;
                if(N != _alpha.at(d).at(pIndex).size()) {
                    cout << "wat.  need this to work" << endl;
                    raise(SIGABRT);
                }

                if((*p_it)->parentA && ((*p_it)->parentA->updated == false || (*p_it)->parentA->updated == false)) {

                    nextItSet.push_back(*p_it);
                    continue;
                }

                // root case
                if((*p_it)->parentA == nullptr) {
                    _alphaGammaRootCase(*ped_it, *p_it, N, d, pIndex, sexIndex, shadingIndex);
                }
                else {
                    _alphaGammaNormalCase(*ped_it, *p_it, N, d, pIndex, sexIndex, shadingIndex);
                }
                (*p_it)->updated = true;

                // add all children to next dfs
                for(auto pair_it=(*p_it)->mateKids.begin(); pair_it!=(*p_it)->mateKids.end(); ++pair_it) {
                    for(auto c_it=pair_it->second.begin(); c_it!=pair_it->second.end(); ++c_it) {             
                        nextItSet.push_back(*c_it);
                    }
                }
            }
            itSet = nextItSet;
        }
        ++d;
    }
}
/*
    // [pedigree][familyUnit][chromosomeFemaleParent][chromosomeMaleParent]
    vector<vector<vector<vector<double>>>> _beta;
*/

int getFamNumb(pedigreeClass2* pedigree, personClass* mateA, personClass* mateB) {

    personClass* femaleParent = nullptr;
    personClass* maleParent = nullptr;
    sortMates(mateA,mateB,femaleParent,maleParent);

    int ans = 0;
    for(auto fam_it=pedigree->families.begin(); fam_it!=pedigree->families.end(); ++fam_it) {

        if(femaleParent == fam_it->at(0) && maleParent == fam_it->at(1)) {
            return ans;
        }
        ++ans;
    }
    cout << "Couldn't find a family with these two mates!" << endl;
    raise(SIGABRT);
    return -1;
}

void EMPedigreeOptimizer::_betaHelper(pedigreeClass2* pedigree, int d, int famNumb) {

    vector<personClass*> currentFam = pedigree->families.at(famNumb);
    personClass* parentA;
    personClass* parentB;
    sortMates(currentFam.at(0),currentFam.at(1),parentA,parentB);
    
    int pAN = parentA->n;
    int pBN = parentB->n;

    for(int i=0; i<pAN; ++i) {

        for(int j=0; j<pBN; ++j) {

            _beta.at(d).at(famNumb).at(i).at(j) = 1.0;

            for(int c=2; c<currentFam.size(); ++c) {
        
                personClass* child = currentFam.at(c);
                int N = child->n;
                int shadingIndex = _emissionMapping.at(child->typeOfShading);
                int sexIndex = getSexIndex(pedigree,child);
                bool isLeaf = find(pedigree->leaves.begin(),pedigree->leaves.end(),child) != pedigree->leaves.end();

                double childSum = 0.0;

                for(int k=0; k<N; ++k) {

                    double A_ijk = _transitionProbs.at(sexIndex).at(i).at(j).at(k);
                    double bVal = _emissionProbs.at(sexIndex).at(k).at(shadingIndex);
                    double mateVal = 1.0;

                    if(isLeaf == false) {
                        for(auto pair_it=child->mateKids.begin(); pair_it!=child->mateKids.end(); ++pair_it) {

                            personClass* mate = pair_it->first;
                            int mateN = mate->n;

                            personClass* mother;
                            personClass* father;
                            sortMates(child,mate,mother,father);

                            int otherFamNumb = getFamNumb(pedigree,mother,father);

                            double betaSum = 0.0;
                            for(int l=0; l<mateN; ++l) {

                                if(child == mother) {
                                    betaSum += _beta.at(d).at(otherFamNumb).at(k).at(l);
                                }
                                else {
                                    betaSum += _beta.at(d).at(otherFamNumb).at(l).at(k);
                                }
                            }

                            mateVal *= betaSum;
                        }
                    }
                    childSum += A_ijk*bVal*mateVal;
                }

                _beta.at(d).at(famNumb).at(i).at(j) *= childSum;
            }
        }
    }
}

void EMPedigreeOptimizer::_updateBeta() {

    int d = 0;
    for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {

        vector<int> itSet = vector<int>();

        // the initial itSet will include all families that have leaves
        for(int i=0; i<(*ped_it)->families.size(); ++i) {

            bool addThis = false;
            for(auto p_it=(*ped_it)->families.at(i).begin(); p_it!=(*ped_it)->families.at(i).end(); ++p_it) {
                bool isLeaf = find((*ped_it)->leaves.begin(),(*ped_it)->leaves.end(),*p_it) != (*ped_it)->leaves.end();
                if(isLeaf) {
                    addThis = true;
                    break;
                }             
            }
            if(addThis) {
                itSet.push_back(i);
            }
        }

        while(itSet.size() > 0) {

            vector<int> nextItSet = vector<int>();

            for(int i=0; i<itSet.size(); ++i) {

                int famNumb = itSet.at(i);
                vector<personClass*> currentFam = (*ped_it)->families.at(famNumb);
                personClass* parentA = currentFam.at(0);
                personClass* parentB = currentFam.at(1);
                if(getFamNumb(*ped_it,parentA,parentB) != famNumb) {
                    cout << "Bug here" << endl;
                    raise(SIGABRT);
                }

                // check to see if good to go on this fam
                bool waitOnThis = false;
                int j=0;
                for(auto p_it=currentFam.begin(); p_it!=currentFam.end(); ++p_it) {

                    bool isLeaf = find((*ped_it)->leaves.begin(),(*ped_it)->leaves.end(),*p_it) != (*ped_it)->leaves.end();
                    if(isLeaf == false && j>1 && (*p_it)->updated == false) {
                        waitOnThis = true;
                        break;
                    }
                    ++j;
                }

                if(waitOnThis) {
                    nextItSet.push_back(famNumb);
                    continue;
                }

                _betaHelper(*ped_it,d,famNumb);

                for(auto p_it=currentFam.begin(); p_it!=currentFam.end(); ++p_it) {
                    (*p_it)->updated = true;
                }

                // add the parents families to the nextItSet
                if(parentA->parentA) {
                    int newFamNumb = getFamNumb(*ped_it,parentA->parentA,parentA->parentB);
                    nextItSet.push_back(newFamNumb);
                }
                if(parentB->parentA) {
                    int newFamNumb = getFamNumb(*ped_it,parentB->parentA,parentB->parentB);
                    nextItSet.push_back(newFamNumb);
                }
            }

            itSet = nextItSet;
        }
        ++d;
    }
}

void EMPedigreeOptimizer::_updateDelta() {

    int d = 0;
    for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {

        for(int f=0; f<(*ped_it)->families.size(); ++f) {

            vector<personClass*> currentFam = (*ped_it)->families.at(f);

            personClass* mother = currentFam.at(0);
            int mIndex = (*ped_it)->mapToIndexAllPeople.at(mother);
            int motherN = mother->n;

            personClass* father = currentFam.at(1);
            int fIndex = (*ped_it)->mapToIndexAllPeople.at(father);
            int fatherN = father->n;

            double total = 0.0;
            for(int i=0; i<motherN; ++i) {

                for(int j=0; j<fatherN; ++j) {

                    double alpha_i_p = _alpha.at(d).at(mIndex).at(i);
                    double alpha_j_q = _alpha.at(d).at(fIndex).at(j);
                    double beta_ij_f = _beta.at(d).at(f).at(i).at(j);

                    _delta.at(d).at(f).at(i).at(j) = alpha_i_p * alpha_j_q * beta_ij_f;
                    total += _delta.at(d).at(f).at(i).at(j);
                }
            }
            for(int i=0; i<motherN; ++i) {
                for(int j=0; j<fatherN; ++j) {
                    _delta.at(d).at(f).at(i).at(j) /= total;
                }
            }
        }
        ++d;
    }
}

void EMPedigreeOptimizer::_updateEpsilon() {

    int d = 0;
    for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {

        for(auto p_it=(*ped_it)->allPeople.begin(); p_it!=(*ped_it)->allPeople.end(); ++p_it) {

            personClass* current = *p_it;
            int currentN = current->n;
            int cIndex = (*ped_it)->mapToIndexAllPeople.at(current);

            double total = 0.0;

            for(int k=0; k<currentN; ++k) {

                double val = _alpha.at(d).at(cIndex).at(k);

                for(auto pair_it=current->mateKids.begin(); pair_it!=current->mateKids.end(); ++pair_it) {

                    personClass* mate = pair_it->first;
                    int mateN = mate->n;
                    int mIndex = (*ped_it)->mapToIndexAllPeople.at(mate);

                    personClass* mother;
                    personClass* father;
                    sortMates(current,mate,mother,father);

                    int f = getFamNumb(*ped_it,mother,father);

                    double sum = 0;

                    for(int l=0; l<mateN; ++l) {

                        double beta_kl_f;
                        if(current == mother) {
                            beta_kl_f = _beta.at(d).at(f).at(k).at(l);
                        }
                        else {
                            beta_kl_f = _beta.at(d).at(f).at(l).at(k);
                        }
                        double gamma_l_m = _gamma.at(d).at(mIndex).at(l);

                        sum += beta_kl_f * gamma_l_m;
                    }

                    val *= sum;
                }
                
                _epsilon.at(d).at(cIndex).at(k) = val;

                total += val;
            }
            for(int k=0; k<currentN; ++k) {
                _epsilon.at(d).at(cIndex).at(k) /= total;
            }
        }
        ++d;
    }
}

void EMPedigreeOptimizer::_updateZeta() {

    int d = 0;
    for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {

        for(int f=0; f<(*ped_it)->families.size(); ++f) {

            vector<personClass*> currentFam = (*ped_it)->families.at(f);

            personClass* mother = currentFam.at(0);
            int mIndex = (*ped_it)->mapToIndexAllPeople.at(mother);
            int motherN = mother->n;

            personClass* father = currentFam.at(1);
            int fIndex = (*ped_it)->mapToIndexAllPeople.at(father);
            int fatherN = father->n;

            double total = 0.0;
            for(int i=0; i<motherN; ++i) {

                for(int j=0; j<fatherN; ++j) {

                    double alpha_i_p = _alpha.at(d).at(mIndex).at(i);
                    double alpha_j_q = _alpha.at(d).at(fIndex).at(j);

                    for(int c=0; c<currentFam.size()-2; ++c) {

                        personClass* child = currentFam.at(c+2);
                        int childN = child->n;
                        int childSex = getSexIndex(*ped_it,child);  
                        int childShading = _emissionMapping.at(child->typeOfShading);

                        for(int k=0; k<childN; ++k) {

                            double A_ijk = _transitionProbs.at(childSex).at(i).at(j).at(k);
                            double B_k_yc = _emissionProbs.at(childSex).at(k).at(childShading);

                            double val = alpha_i_p * alpha_j_q * A_ijk * B_k_yc;

                            for(auto pair_it=child->mateKids.begin(); pair_it!=child->mateKids.end(); ++pair_it) {

                                personClass* mate = pair_it->first;
                                int mateL = mate->n;
                                int mateIndex = (*ped_it)->mapToIndexAllPeople.at(mate);

                                personClass* female;
                                personClass* male;
                                sortMates(child,mate,female,male);

                                int famNumb = getFamNumb(*ped_it,female,male);

                                double sum = 0.0;

                                for(int l=0; l<mateL; ++l) {

                                    double beta_kl_f;
                                    if(child == female) {
                                        beta_kl_f = _beta.at(d).at(famNumb).at(k).at(l);
                                    }
                                    else {
                                        beta_kl_f = _beta.at(d).at(famNumb).at(l).at(k);
                                    }
                                    double gamma_l_m = _gamma.at(d).at(mateIndex).at(l);

                                    sum += beta_kl_f * gamma_l_m;
                                }

                                val *= sum;
                            }

                            _zeta.at(d).at(f).at(i).at(j).at(c).at(childSex).at(k) = val;
                            total += val;

                        }

                    }
                }
            }
            for(int i=0; i<motherN; ++i) {
                for(int j=0; j<fatherN; ++j) {
                    for(int c=0; c<currentFam.size()-2; ++c) {

                        personClass* child = currentFam.at(c+2);
                        int childN = child->n;
                        int childSex = getSexIndex(*ped_it,child);  

                        for(int k=0; k<childN; ++k) {

                            _zeta.at(d).at(f).at(i).at(j).at(c).at(childSex).at(k) /= total;
                        }
                    }
                }
            }
        }
        ++d;
    }
}

void EMPedigreeOptimizer::_updateRootProbs() {

}

void EMPedigreeOptimizer::_updateEmissionProbs() {

}

void EMPedigreeOptimizer::_updateTransitionProbs() {

}




void EMPedigreeOptimizer::_eStep() {
    _resetPedigrees();
    _updateAlphaGamma();
    _resetPedigrees();
    _updateBeta();
    _updateDelta();
    _updateEpsilon();
    _updateZeta();
}

void EMPedigreeOptimizer::_mStep() {
//    _updateRootProbs();
//    _updateEmissionProbs();
//    _updateTransitionProbs();
}

void EMPedigreeOptimizer::_EMStep() {
    _eStep();
    _mStep();
}






