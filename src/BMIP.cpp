// #include "BMIP.h"


// #define PRECISION pow(10,-15)


// void EMPedigreeOptimizer::_checkC() {

//     // make sure that correct part sums to 1

//     for(int i=0; i<_c.size(); ++i) {
//         for(int j=0; j<_c.at(i).size(); ++j) {
//             double epsSum = 0.0;
//             for(int k=0; k<_c.at(i).at(j).size(); ++k) {
//                 epsSum += _c.at(i).at(j).at(k);
//             }
//             if(abs(epsSum-1.0) > PRECISION) {
//                 raise(SIGABRT);
//             }
//         }
//     }
// }


// void EMPedigreeOptimizer::_checkD() {

//     // make sure that marginalizing out p,q -> 1

//     for(int i=0; i<_d.size(); ++i) {
//         for(int j=0; j<_d.at(i).size(); ++j) {
//             double deltaSum = 0.0;
//             for(int k=0; k<_d.at(i).at(j).size(); ++k) {
//                 for(int l=0; l<_d.at(i).at(j).at(k).size(); ++l) {
//                     deltaSum += _d.at(i).at(j).at(k).at(l);
//                 }
//             }
//             if(abs(deltaSum-1.0) > PRECISION) {
//                 raise(SIGABRT);
//             }
//         }
//     }

//     // make sure that marginalizing out p -> epsilon(q) and q -> epsilon(p)
    
//     // pedigree
//     for(int i=0; i<_d.size(); ++i) {
        
//         // familyUnit
//         for(int j=0; j<_d.at(i).size(); ++j) {

//             vector<personClass*> family = _trainingSet.at(i)->families.at(j);
//             personClass* mother = family.at(0);
//             personClass* father = family.at(1);
//             int motherIndex = _trainingSet.at(i)->mapToIndexAllPeople.at(mother);
//             int fatherIndex = _trainingSet.at(i)->mapToIndexAllPeople.at(father);
            
//             // chromosomeFemaleParent
//             for(int k=0; k<_d.at(i).at(j).size(); ++k) {

//                 double deltaSum = 0.0;
                
//                 // chromosomeMaleParent
//                 for(int l=0; l<_d.at(i).at(j).at(k).size(); ++l) {

//                     double deltaVal = _d.at(i).at(j).at(k).at(l);
//                     deltaSum += deltaVal;
//                 }

//                 double epsilon_val = _c.at(i).at(motherIndex).at(k);
//                 if(abs(deltaSum-epsilon_val) > PRECISION) {
//                     raise(SIGABRT);
//                 }
//             }

//             for(int l=0; l<_maleN; ++l) {
//                 double deltaSum = 0.0;
//                 for(int k=0; k<_femaleN; ++k) {
//                     double deltaVal = _d.at(i).at(j).at(k).at(l);
//                     deltaSum += deltaVal;
//                 }
                
//                 double epsilon_val = _c.at(i).at(fatherIndex).at(l);
//                 if(abs(deltaSum-epsilon_val) > PRECISION) {
//                     raise(SIGABRT);
//                 }
//             }
//         }
//     }
// }


// void EMPedigreeOptimizer::_checkE() {
//     // pedigree
//     for(int i=0; i<_e.size(); ++i) {
//         // familyUnit
//         for(int j=0; j<_e.at(i).size(); ++j) {
            
//             double sum = 0.0;
            
//             // chromosomeFemaleParent
//             for(int k=0; k<_e.at(i).at(j).size(); ++k) {
//                 // chromosomeMaleParent
//                 for(int l=0; l<_e.at(i).at(j).at(k).size(); ++l) {
                    
//                     // childNumber
//                     for(int i2=0; i2<_e.at(i).at(j).at(k).at(l).size(); ++i2) {
                        
//                         double marginalizeSum = 0.0;
                        
//                         // childSexIndex
//                         for(int j2=0; j2<_e.at(i).at(j).at(k).at(l).at(i2).size(); ++j2) {
                            
//                             // childChromosome
//                             for(int k2=0; k2<_e.at(i).at(j).at(k).at(l).at(i2).at(j2).size(); ++k2) {
                                
//                                 // only going to do first thing (because rest will probably work)
//                                 if(i2 == 0 && j2 == 0) {
//                                     sum += _e.at(i).at(j).at(k).at(l).at(i2).at(j2).at(k2);
//                                 }
                                
//                                 marginalizeSum += _e.at(i).at(j).at(k).at(l).at(i2).at(j2).at(k2);
//                             }
//                         }
//                         double compareAgainst = _d.at(i).at(j).at(k).at(l);
//                         if(abs(marginalizeSum-compareAgainst) > PRECISION) {
//                             raise(SIGABRT);
//                         }
//                     }
//                 }
//             }
//             if((sum-1.0) > PRECISION) {
//                 raise(SIGABRT);
//             }
//         }
//     }
// }



// void EMPedigreeOptimizer::sortMates(personClass* mateA, personClass* mateB, personClass*& femaleMate, personClass*& maleMate) {
//     if(mateA->sex == "female") {
//         femaleMate = mateA;
//         maleMate = mateB;
//     }
//     else {
//         maleMate = mateA;
//         femaleMate = mateB;
//     }
// }

// int EMPedigreeOptimizer::getFamNumb(pedigreeClass2* pedigree, personClass* mateA, personClass* mateB) {
    
//     personClass* femaleParent = nullptr;
//     personClass* maleParent = nullptr;
//     sortMates(mateA,mateB,femaleParent,maleParent);
    
//     int ans = 0;
//     for(auto fam_it=pedigree->families.begin(); fam_it!=pedigree->families.end(); ++fam_it) {
        
//         if(femaleParent == fam_it->at(0) && maleParent == fam_it->at(1)) {
//             return ans;
//         }
//         ++ans;
//     }
//     cout << "Couldn't find a family with these two mates!" << endl;
//     raise(SIGABRT);
//     return -1;
// }


// int EMPedigreeOptimizer::getSexIndex(pedigreeClass2* pedigree, personClass* person) {
//     int sexIndex = 0;
//     if(pedigree->sexDependent) {
//         if(person->sex == "male") {
//             sexIndex = 0;
//         }
//         else if(person->sex == "female") {
//             sexIndex = 1;
//         }
//         else if(person->sex == "unknown") {
//             sexIndex = 2;
//         }
//         else {
//             cout << "Invalid sex" << endl;
//             raise(SIGABRT);
//         }
//     }
//     return sexIndex;
// }



// void EMPedigreeOptimizer::initialize(const vector<pedigreeClass2*> & trainingSet_, bool printPeople) {
    
//     _trainingSet = trainingSet_;
    
//     // initialize the _emissionProbs and _transitionProbs
//     bool sexDependent = _trainingSet.at(0)->sexDependent;
//     int femaleN = -1;
//     int maleN = -1;
//     int unknownN = -1;
    
//     int index=0;
    
//     for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {
        
//         if(printPeople) {
//             (*ped_it)->printAllPeople("z"+to_string(index)+"z");
//         }
        
//         if(sexDependent != (*ped_it)->sexDependent) {
//             cout << "NEED SAME SEX DEPENDENCY!!" << endl;
//             raise(SIGABRT);
//         }
        
//         for(auto p_it=(*ped_it)->allPeople.begin(); p_it!=(*ped_it)->allPeople.end(); ++p_it) {
            
//             if((*p_it)->parentA && (*p_it)->parentA->sex == "unknown") {
//                 cout << "DONT SUPPORT THIS CASE YET" << endl;
//                 raise(SIGABRT);
//             }
            
//             string sex = (*p_it)->sex;
//             int n = (*p_it)->n;
            
//             if(sex == "male") {
//                 if(maleN != -1) {
//                     if(maleN != n) {
//                         cout << "INCONSISTENT " << maleN << endl;
//                         raise(SIGABRT);
//                     }
//                 }
//                 else {
//                     maleN = n;
//                 }
//             }
//             else if(sex == "female") {
//                 if(femaleN != -1) {
//                     if(femaleN != n) {
//                         cout << "INCONSISTENT " << femaleN << endl;
//                         raise(SIGABRT);
//                     }
//                 }
//                 else {
//                     femaleN = n;
//                 }
//             }
//             else if(sex == "unknown") {
//                 if(unknownN != -1) {
//                     if(unknownN != n) {
//                         cout << "INCONSISTENT " << unknownN << endl;
//                         raise(SIGABRT);
//                     }
//                 }
//                 else {
//                     unknownN = n;
//                 }
//             }
//             else {
//                 cout << "INVALID SEX!!" << endl;
//                 raise(SIGABRT);
//             }
//         }
//         ++index;
//     }
    
//     _femaleN = femaleN;
//     _maleN = maleN;
//     _unknownN = unknownN;
//     if(unknownN == -1) {
//         // no unknown people
//         unknownN = 0;
//         _unknownN = 0;
//     }
//     _sexDependent = sexDependent;
    
//     if(printPeople) {
//         string toPrint = "\nvector<pedigreeClass2*> trainingSet({";
        
//         index = 0;
//         for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {
//             if(index+1 != _trainingSet.size()) {
//                 toPrint += "&pedigreez"+to_string(index)+"z"+",";
//             }
//             else {
//                 toPrint += "&pedigreez"+to_string(index)+"z";
//             }
//             ++index;
//         }
//         toPrint += "});\n";
//         toPrint += "EMPedigreeOptimizer empo;\n";
//         toPrint += "empo.initialize(trainingSet,false);\n";
//         cout << toPrint;
//     }
    
//     if(sexDependent) {
//         // sex is one of ['female','male','unknown']
//         _emissionProbs = vector<vector<vector<double>>>(3);
//         _emissionProbs.at(0) = vector<vector<double>>(femaleN,vector<double>(4));
//         _emissionProbs.at(1) = vector<vector<double>>(maleN,vector<double>(4));
//         _emissionProbs.at(2) = vector<vector<double>>(unknownN,vector<double>(4));
        
//         // WILL ASSUME THAT THERE ARE NO UNKNOWN,UNKNOWN -> CHILD FAMILIES
//         _transitionProbs = vector<vector<vector<vector<double>>>>(3);
//         _transitionProbs.at(0) = vector<vector<vector<double>>>(femaleN,vector<vector<double>>(maleN,vector<double>(maleN)));
//         _transitionProbs.at(1) = vector<vector<vector<double>>>(femaleN,vector<vector<double>>(maleN,vector<double>(femaleN)));
//         _transitionProbs.at(2) = vector<vector<vector<double>>>(femaleN,vector<vector<double>>(maleN,vector<double>(unknownN)));
//     }
//     else {
//         // emmision can be ['shaded', 'possiblyShaded', 'unshaded', 'carrier']
//         _emissionProbs = vector<vector<vector<double>>>(1);
//         _emissionProbs.at(0) = vector<vector<double>>(maleN,vector<double>(4));
//         _transitionProbs = vector<vector<vector<vector<double>>>>(1);
//         _transitionProbs.at(0) = vector<vector<vector<double>>>(femaleN,vector<vector<double>>(maleN,vector<double>(maleN)));
//     }
    
//     /*
//      ========================================================
//      */
    
//     // initialize the _rootProbs
//     for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {
        
//         vector<vector<double>> rootsToAdd;
//         for(auto r_it=(*ped_it)->roots.begin(); r_it!=(*ped_it)->roots.end(); ++r_it) {
            
//             int n = (*r_it)->n;
//             vector<double> rootToAdd(n);
//             // randomly initialize (for the moment)
//             double total = 0.0;
//             for(int i=0; i<n; ++i) {
//                 double randomNumb = 1;//rand()/(double)RAND_MAX;
//                 total += randomNumb;
//                 rootToAdd.at(i) = randomNumb;
//             }
//             for(int i=0; i<n; ++i) {
//                 rootToAdd.at(i) /= total;
//             }
//             rootsToAdd.push_back(rootToAdd);
            
//         }
//         _rootProbs.push_back(rootsToAdd);
//     }
    
//     // initialize the _transitionProbs
//     // sum over motherChrom fatherChrom should sum to 1 for each childSex
//     for(int i=0; i<_transitionProbs.size(); ++i) {
        
//         vector<vector<double>> sums = vector<vector<double>>();
        
//         for(int j=0; j<_transitionProbs.at(i).size(); ++j) {
//             sums.push_back(vector<double>(_transitionProbs.at(i).at(j).size(),0));
            
//             for(int k=0; k<_transitionProbs.at(i).at(j).size(); ++k) {
                
//                 for(int l=0; l<_transitionProbs.at(i).at(j).at(k).size(); ++l) {
//                     double randomNumb = rand()/(double)RAND_MAX;
//                     _transitionProbs.at(i).at(j).at(k).at(l) = randomNumb;
//                     sums.at(j).at(k) += randomNumb;
//                 }
//             }
//         }
//         for(int j=0; j<_transitionProbs.at(i).size(); ++j) {
//             for(int k=0; k<_transitionProbs.at(i).at(j).size(); ++k) {
//                 for(int l=0; l<_transitionProbs.at(i).at(j).at(k).size(); ++l) {
//                     _transitionProbs.at(i).at(j).at(k).at(l) /= sums.at(j).at(k);
//                 }
//             }
//         }
//     }
    
    
    
//     // sum over shading observations should equal 1
//     // initialize the _emissionProbs
//     for(int i=0; i<_emissionProbs.size(); ++i) {
//         for(int j=0; j<_emissionProbs.at(i).size(); ++j) {
//             double sum = 0.0;
//             for(int k=0; k<_emissionProbs.at(i).at(j).size(); ++k) {
//                 double randomNumb = rand()/(double)RAND_MAX;
//                 sum += randomNumb;
//                 _emissionProbs.at(i).at(j).at(k) = randomNumb;
//             }
//             for(int k=0; k<_emissionProbs.at(i).at(j).size(); ++k) {
//                 _emissionProbs.at(i).at(j).at(k) /= sum;
//             }
//         }
//     }

//     _u = vector<vector<vector<pair<int,double>>>>();
//     _w = vector<vector<vector<vector<vector<pair<int,double>>>>>>();
//     _a = vector<vector<vector<vector<pair<int,double>>>>>();
//     _b = vector<vector<vector<vector<vector<vector<pair<int,double>>>>>>>();

//     _c = vector<vector<vector<double>>>();
//     _d = vector<vector<vector<vector<double>>>>();
//     _e = vector<vector<vector<vector<vector<vector<vector<double>>>>>>>();
    
//     for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {
        
//         vector<vector<pair<int,double>>> people = vector<vector<pair<int,double>>>();
//         vector<vector<double>> people2 = vector<vector<double>>();
//         for(auto p_it=(*ped_it)->allPeople.begin(); p_it!=(*ped_it)->allPeople.end(); ++p_it) {
            
//             int N = (*p_it)->n;
//             vector<pair<int,double>> toAdd = vector<pair<int,double>>(N,pair<int,double>(false,0));
//             people.push_back(toAdd);
//             vector<double> toAdd2 = vector<double>(N,0);
//             people2.push_back(toAdd2);
//         }
//         _u.push_back(people);
//         _c.push_back(people2);   


//         int numFams = (int)(*ped_it)->families.size();

//         vector<vector<vector<vector<pair<int,double>>>>> vAddition(numFams,
//                           vector<vector<vector<pair<int,double>>>>({
//                                   vector<vector<pair<int,double>>>(_femaleN,vector<pair<int,double>>(_maleN,pair<int,double>(false,0))),
//                                   vector<vector<pair<int,double>>>(_maleN,vector<pair<int,double>>(_femaleN,pair<int,double>(false,0)))}));

//         vector<vector<vector<pair<int,double>>>> aAddition(numFams,
//                           vector<vector<pair<int,double>>>({
//                                   vector<pair<int,double>>(_femaleN,pair<int,double>(false,0)),
//                                   vector<pair<int,double>>(_maleN,pair<int,double>(false,0))}));

//         vector<vector<vector<vector<vector<pair<int,double>>>>>> bAddition = vector<vector<vector<vector<vector<pair<int,double>>>>>>(numFams,
//                                                                                    vector<vector<vector<vector<pair<int,double>>>>>(_femaleN,
//                                                                                            vector<vector<vector<pair<int,double>>>>(_maleN)));

//         vector<vector<vector<double>>> dAddition(numFams,
//                           vector<vector<double>>(_femaleN,
//                                   vector<double>(_maleN)));

//         vector<vector<vector<vector<vector<vector<double>>>>>> eAddition = vector<vector<vector<vector<vector<vector<double>>>>>>(numFams,
//                                                                                    vector<vector<vector<vector<vector<double>>>>>(_femaleN,
//                                                                                            vector<vector<vector<vector<double>>>>(_maleN)));

        
//         for(int f=0; f<(*ped_it)->families.size(); ++f) {
            
//             int numbChildren = (int)(*ped_it)->families.at(f).size()-2;
//             vector<vector<pair<int,double>>> lastBPart;
//             vector<vector<vector<double>>> lastEPart;
//             if(_sexDependent) {

//                 lastBPart = vector<vector<pair<int,double>>>(numbChildren,
//                                     vector<pair<int,double>>(3,pair<int,double>(false,0)));

//                 lastEPart = vector<vector<vector<double>>>(numbChildren,
//                                     vector<vector<double>>({
//                                             vector<double>(_femaleN),
//                                             vector<double>(_maleN),
//                                             vector<double>(_unknownN)}));
//             }
//             else {
//                 lastBPart = vector<vector<pair<int,double>>>(numbChildren,
//                                     vector<pair<int,double>>(1,pair<int,double>(false,0)));

//                 lastEPart = vector<vector<vector<double>>>(numbChildren,
//                                     vector<vector<double>>(1,
//                                             vector<double>(_femaleN)));
//             }
            
//             for(int i=0; i<_femaleN; ++i) {
//                 for(int j=0; j<_maleN; ++j) {
//                     bAddition.at(f).at(i).at(j) = lastBPart;
//                     eAddition.at(f).at(i).at(j) = lastEPart;
//                 }
//             }
//         }
        
//         _w.push_back(vAddition);
//         _a.push_back(aAddition);
//         _b.push_back(bAddition);
//         _d.push_back(dAddition);
//         _e.push_back(eAddition);   
//     }
// }


// // _u -> [pedigree (d)][person (c)][chromosome (k)] -> u_k(c)
// double EMPedigreeOptimizer::_getUVal(pedigreeClass2* pedigree, int d, personClass* child, int k) {

//     int c = pedigree->mapToIndexAllPeople.at(child);

//     pair<int,double> spot = _u.at(d).at(c).at(k);
//     int status = spot.first;
//     if(status == 0) {
//         _computeUVal(pedigree,d,child,k);
//     }
//     else if(status == 2) {
//         cout << "ALREADY COMPUTING VALUE" << endl;
//         raise(SIGABRT);
//     }
//     double uVal = _u.at(d).at(c).at(k).second;
//     return uVal;
// }

// // _w -> [pedigree (d)][familyUnit (f)][p==mother][parentAChromosome (i)][parentBChromosome (j)] -> w_ij(q|p)
// double EMPedigreeOptimizer::_getWVal(pedigreeClass2* pedigree, int d, int f, int motherIsP, int i, int j) {

//     pair<int,double> spot = _w.at(d).at(f).at(motherIsP).at(i).at(j);
//     int status = spot.first;
//     if(status == 0) {
//         _computeWVal(pedigree,d,f,motherIsP,i,j);
//     }
//     else if(status == 2) {
//         cout << "ALREADY COMPUTING VALUE" << endl;
//         raise(SIGABRT);
//     }
//     double uVal = _w.at(d).at(f).at(motherIsP).at(i).at(j).second;
//     return uVal;
// }

// // _a -> [pedigree (d)][familyUnit (f)][p==mother][parentAChromosome (i)] -> a_i(p,q)
// double EMPedigreeOptimizer::_getAVal(pedigreeClass2* pedigree, int d, int f, int motherIsP, int i) {

//     pair<int,double> spot = _a.at(d).at(f).at(motherIsP).at(i);
//     int status = spot.first;
//     if(status == 0) {
//         _computeAVal(pedigree,d,f,motherIsP,i);
//     }
//     else if(status == 2) {
//         cout << "ALREADY COMPUTING VALUE" << endl;
//         raise(SIGABRT);
//     }
//     double uVal = _a.at(d).at(f).at(motherIsP).at(i).second;
//     return uVal;
// }

// // _b -> [pedigree (d)][familyUnit (f)][motherChromosome (i)][fatherChromosome (j)][childNumber (c)][childSexIndex] -> b_ij(c)
// double EMPedigreeOptimizer::_getBVal(pedigreeClass2* pedigree, int d, int f, int i, int j, personClass* child, int c) {
    
//     int sexIndex = getSexIndex(pedigree,child);
//     pair<int,double> spot = _b.at(d).at(f).at(i).at(j).at(c).at(sexIndex);
//     int status = spot.first;
//     if(status == 0) {
//         _computeBVal(pedigree,d,f,i,j,child,c);
//     }
//     else if(status == 2) {
//         cout << "ALREADY COMPUTING VALUE" << endl;
//         raise(SIGABRT);
//     }
//     double uVal = _b.at(d).at(f).at(i).at(j).at(c).at(sexIndex).second;
//     return uVal;

// }

// // _a -> [pedigree (d)][familyUnit (f)][p==mother][parentAChromosome (i)] -> a_i(p,q)
// void EMPedigreeOptimizer::_computeAVal(pedigreeClass2* pedigree, int d, int f, int motherIsP, int i) {

//     if(_a.at(d).at(f).at(motherIsP).at(i).first == 1) {
//         return;
//     }
//     else if(_a.at(d).at(f).at(motherIsP).at(i).first == 2) {
//         cout << "can't happen" << endl;
//         raise(SIGABRT);
//     }
//     _a.at(d).at(f).at(motherIsP).at(i).first = 2;

//     const vector<personClass*>& family = pedigree->families.at(f);
//     personClass* mother = family.at(0);
//     personClass* father = family.at(1);

//     personClass* p;
//     personClass* q;
//     if(motherIsP) {
//         p = mother;
//         q = father;
//     }
//     else {
//         p = father;
//         q = mother;
//     }

//     double u_i_p = _getUVal(pedigree,d,p,i);

//     double mProd = 1.0;
//     for(auto pair_it=p->mateKids.begin(); pair_it!=p->mateKids.end(); ++pair_it) {

//         personClass* mate = pair_it->first;
//         if(mate == q) {
//             continue;
//         }
//         int mateN = mate->n;

//         personClass* mother_;
//         personClass* father_;
//         sortMates(p,mate,mother_,father_);
//         int newF = getFamNumb(pedigree,mother_,father_);

//         double sum = 0.0;
//         for(int i_=0; i_<mateN; ++i_) {

//             double w_ii__mp = _getWVal(pedigree,d,newF,motherIsP,i,i_);
//             sum += w_ii__mp;
//         }
//         mProd *= sum;
//     }

//     double val = u_i_p * mProd;

//     _a.at(d).at(f).at(motherIsP).at(i).first = 1;
//     _a.at(d).at(f).at(motherIsP).at(i).second = val;
// }

// // _b -> [pedigree (d)][familyUnit (f)][motherChromosome (i)][fatherChromosome (j)][childNumber (c)][childSexIndex] -> b_ij(c)
// void EMPedigreeOptimizer::_computeBVal(pedigreeClass2* pedigree, int d, int f, int i, int j, personClass* child, int c) {

//     int sexIndex = getSexIndex(pedigree,child);


//     if(_b.at(d).at(f).at(i).at(j).at(c).at(sexIndex).first == 1) {
//         return;
//     }
//     else if(_b.at(d).at(f).at(i).at(j).at(c).at(sexIndex).first == 2) {
//         cout << "can't happen" << endl;
//         raise(SIGABRT);
//     }
//     _b.at(d).at(f).at(i).at(j).at(c).at(sexIndex).first = 2;

//     int shadingIndex = _emissionMapping.at(child->typeOfShading);
//     int childN = child->n;
//     int motherIsP = (int)(child->sex=="female");

//     double val = 0.0;
//     for(int k=0; k<childN; ++k) {

//         double A_ijk = _transitionProbs.at(sexIndex).at(i).at(j).at(k);
//         double bVal = _emissionProbs.at(sexIndex).at(k).at(shadingIndex);

//         double cProd = 1.0;
//         for(auto pair_it=child->mateKids.begin(); pair_it!=child->mateKids.end(); ++pair_it) {

//             personClass* mate = pair_it->first;
//             personClass* mother;
//             personClass* father;
//             sortMates(child,mate,mother,father);
//             int newF = getFamNumb(pedigree,mother,father);


//             int mateN = mate->n;

//             double sum = 0.0;
//             for(int k_=0; k_<mateN; ++k_) {

//                 double w_kk__mc;
//                 w_kk__mc = _getWVal(pedigree,d,newF,motherIsP,k,k_);
//                 sum += w_kk__mc;
//             }
//             cProd *= sum;
//         }
//         val += A_ijk * bVal * cProd;
//     }


//     _b.at(d).at(f).at(i).at(j).at(c).at(sexIndex).first = 1;
//     _b.at(d).at(f).at(i).at(j).at(c).at(sexIndex).second = val;
// }

// // _u -> [pedigree (d)][person (c)][chromosome (k)] -> u_k(c)
// void EMPedigreeOptimizer::_computeUVal(pedigreeClass2* pedigree, int d, personClass* child, int k) {

//     int cIndex = pedigree->mapToIndexAllPeople.at(child);

//     if(_u.at(d).at(cIndex).at(k).first == 1) {
//         return;
//     }
//     else if(_u.at(d).at(cIndex).at(k).first == 2) {
//         cout << "Can't be doing this!" << endl;
//         raise(SIGABRT);
//     }
//     _u.at(d).at(cIndex).at(k).first = 2;

//     int shadingIndex = _emissionMapping.at(child->typeOfShading);
//     int sexIndex = getSexIndex(pedigree,child);

//     double val = -1;
//     if(child->parentA == nullptr) {

//         int rIndex = pedigree->mapToIndexRoots.at(child);
//         double piVal = _rootProbs.at(d).at(rIndex).at(k);
//         double bVal = _emissionProbs.at(sexIndex).at(k).at(shadingIndex);
//         val = piVal*bVal;
//     }
//     else {

//         personClass* mother;
//         personClass* father;
//         sortMates(child->parentA,child->parentB,mother,father);

//         int motherN = mother->n;
//         int fatherN = father->n;
        
        
//         int f = getFamNumb(pedigree,mother,father);
//         const vector<personClass*>& family = pedigree->families.at(f);

//         double sum = 0.0;
//         for(int i=0; i<motherN; ++i) {

//             double a_i_pq = _getAVal(pedigree,d,f,true,i);
//             for(int j=0; j<fatherN; ++j) {

//                 double A_ijk = _transitionProbs.at(sexIndex).at(i).at(j).at(k);
//                 double bVal = _emissionProbs.at(sexIndex).at(k).at(shadingIndex);
//                 double a_j_qp = _getAVal(pedigree,d,f,false,j);

//                 double sProd = 1.0;
//                 for(int s=0; s<family.size()-2; ++s) {

//                     personClass* sibling = family.at(s+2);

//                     if(sibling == child) {
//                         continue;
//                     }
//                     double b_ij_s = _getBVal(pedigree,d,f,i,j,sibling,s);
                    
//                     sProd *= b_ij_s;
//                 }
//                 sum += A_ijk * bVal * a_i_pq * a_j_qp * sProd;
//             }
//         }
//         val = sum;
//     }

//     _u.at(d).at(cIndex).at(k).first = 1;
//     _u.at(d).at(cIndex).at(k).second = val;
// }

// // _w -> [pedigree (d)][familyUnit (f)][p==mother][parentAChromosome (i)][parentBChromosome (j)] -> w_ij(q|p)
// void EMPedigreeOptimizer::_computeWVal(pedigreeClass2* pedigree, int d, int f, int motherIsP, int i, int j) {

//     if(_w.at(d).at(f).at(motherIsP).at(i).at(j).first == 1) {
//         return;
//     }
//     else if(_w.at(d).at(f).at(motherIsP).at(i).at(j).first == 2) {
//         cout << "can't happen" << endl;
//         raise(SIGABRT);
//     }
//     _w.at(d).at(f).at(motherIsP).at(i).at(j).first = 2;



//     const vector<personClass*>& family = pedigree->families.at(f);
//     personClass* mother = family.at(0);
//     personClass* father = family.at(1);

//     personClass* p;
//     personClass* q;
//     if(motherIsP) {
//         p = mother;
//         q = father;
//     }
//     else {
//         p = father;
//         q = mother;
//     }

//     double val = -1;

//     bool isLeaf = find(pedigree->leaves.begin(),pedigree->leaves.end(),p) != pedigree->leaves.end();
//     if(isLeaf) {
//         val = 1.0;
//     }
//     else {

//         double a_j_qp = _getAVal(pedigree,d,f,!motherIsP,j);
//         double cProd = 1.0;
//         for(int c=0; c<family.size()-2; ++c) {

//             personClass* child = family.at(c+2);
//             double b_ij_c;
//             if(motherIsP) {
//                 b_ij_c = _getBVal(pedigree,d,f,i,j,child,c);
//             }
//             else {
//                 b_ij_c = _getBVal(pedigree,d,f,j,i,child,c);
//             }
//             cProd *= b_ij_c;
//         }

//         val = a_j_qp * cProd;
//     }

//     _w.at(d).at(f).at(motherIsP).at(i).at(j).first = 1;
//     _w.at(d).at(f).at(motherIsP).at(i).at(j).second = val;
// }

// void EMPedigreeOptimizer::_cUpdate() {

//     int d = 0;
//     for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {

//         pedigreeClass2* pedigree = *ped_it;

//         for(auto p_it=pedigree->allPeople.begin(); p_it!=pedigree->allPeople.end(); ++p_it) {

//             personClass* person = *p_it;
//             int personN = person->n;
//             int pIndex = pedigree->mapToIndexAllPeople.at(person);

//             double total = 0.0;
//             for(int i=0; i<personN; ++i) {

//                 double u_i_p = _getUVal(pedigree,d,person,i);
//                 double mProd = 1.0;
//                 for(auto pair_it=person->mateKids.begin(); pair_it!=person->mateKids.end(); ++pair_it) {

//                     personClass* mate = pair_it->first;
//                     int mateN = mate->n;

//                     personClass* mother;
//                     personClass* father;
//                     sortMates(person,mate,mother,father);
//                     int f = getFamNumb(pedigree,mother,father);

//                     double sum = 0.0;
//                     for(int j=0; j<mateN; ++j) {

//                         double w_ij_mp;
//                         w_ij_mp = _getWVal(pedigree,d,f,(int)(person == mother),i,j);
//                         sum += w_ij_mp;
//                     }
//                     mProd *= sum;
//                 }
                
//                 double val = u_i_p * mProd;
//                 _c.at(d).at(pIndex).at(i) = val;
//                 total += val;
//             }
//             double sum = 0.0;
//             for(int i=0; i<personN; ++i) {
//                 _c.at(d).at(pIndex).at(i) /= total;
//                 sum += _c.at(d).at(pIndex).at(i);
//             }
//             if(abs(sum-1.0) > PRECISION) {
//                 raise(SIGABRT);
//             }
//         }
//         ++d;
//     }
// }

// // void EMPedigreeOptimizer::_dUpdate() {

// //     int d = 0;
// //     for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {

// //         pedigreeClass2* pedigree = *ped_it;

// //         for(int f=0; f<pedigree->families.size(); ++f) {

// //             vector<personClass*> family = pedigree->families.at(f);
// //             personClass* mother = family.at(0);
// //             personClass* father = family.at(1);
// //             int motherN = mother->n;
// //             int fatherN = father->n;
// //             int mIndex = pedigree->mapToIndexAllPeople.at(mother);
// //             int fIndex = pedigree->mapToIndexAllPeople.at(father);

// //             double total = 0.0;
// //             for(int i=0; i<motherN; ++i) {

// //                 double a_i_pq = _getAVal(pedigree,d,f,true,i);
// //                 for(int j=0; j<fatherN; ++j) {

// //                     double a_j_qp = _getAVal(pedigree,d,f,false,j);

// //                     double cProd = 1.0;
// //                     for(int c=0; c<family.size()-2; ++c) {

// //                         personClass* child = family.at(c+2);
// //                         double b_ij_c = _getBVal(pedigree,d,f,i,j,child,c);
// //                         cProd *= b_ij_c;
// //                     }

// //                     double val = a_i_pq * a_j_qp * cProd;
// //                     _d.at(d).at(f).at(i).at(j) = val;
// //                     total += val;
// //                 }
// //             }

// //             vector<double> sums(fatherN,0);
// //             for(int i=0; i<motherN; ++i) {

// //                 double marginalizeSum = 0.0;
// //                 for(int j=0; j<fatherN; ++j) {

// //                     _d.at(d).at(f).at(i).at(j) /= total;
// //                     double val = _d.at(d).at(f).at(i).at(j);
// //                     marginalizeSum += val;
// //                     sums.at(j) += val;
// //                 }
// //                 double compareAgainst = _c.at(d).at(mIndex).at(i);
// //                 if(abs(marginalizeSum-compareAgainst) > PRECISION) {
// //                     raise(SIGABRT);
// //                 }
// //             }
// //             for(int j=0; j<fatherN; ++j) {

// //                 double marginalizeSum = sums.at(j);
// //                 double compareAgainst = _c.at(d).at(fIndex).at(j);
// //                 if(abs(marginalizeSum-compareAgainst) > PRECISION) {
// //                     raise(SIGABRT);
// //                 }
// //             }
// //         }
// //         ++d;
// //     }
// // }


// void EMPedigreeOptimizer::_dUpdate() {

//     int d = 0;
//     for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {

//         pedigreeClass2* pedigree = *ped_it;

//         for(int f=0; f<pedigree->families.size(); ++f) {

//             vector<personClass*> family = pedigree->families.at(f);
//             personClass* mother = family.at(0);
//             personClass* father = family.at(1);
//             int motherN = mother->n;
//             int fatherN = father->n;
//             int mIndex = pedigree->mapToIndexAllPeople.at(mother);
//             int fIndex = pedigree->mapToIndexAllPeople.at(father);

//             double total = 0.0;
//             for(int i=0; i<motherN; ++i) {

//                 double a_i_pq = _getAVal(pedigree,d,f,true,i);
//                 for(int j=0; j<fatherN; ++j) {

//                     double w_ij_qp = _getWVal(pedigree,d,f,true,i,j);
//                     double val = a_i_pq * w_ij_qp;
//                     _d.at(d).at(f).at(i).at(j) = val;
//                     total += val;
//                 }
//             }

//             vector<double> sums(fatherN,0);
//             for(int i=0; i<motherN; ++i) {

//                 double marginalizeSum = 0.0;
//                 for(int j=0; j<fatherN; ++j) {

//                     _d.at(d).at(f).at(i).at(j) /= total;
//                     double val = _d.at(d).at(f).at(i).at(j);
//                     marginalizeSum += val;
//                     sums.at(j) += val;
//                 }
//                 double compareAgainst = _c.at(d).at(mIndex).at(i);
//                 if(abs(marginalizeSum-compareAgainst) > PRECISION) {
//                     raise(SIGABRT);
//                 }
//             }
//             for(int j=0; j<fatherN; ++j) {

//                 double marginalizeSum = sums.at(j);
//                 double compareAgainst = _c.at(d).at(fIndex).at(j);
//                 if(abs(marginalizeSum-compareAgainst) > PRECISION) {
//                     raise(SIGABRT);
//                 }
//             }
//         }
//         ++d;
//     }
// }

// void EMPedigreeOptimizer::_eUpdate() {

//     int d = 0;
//     for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {

//         pedigreeClass2* pedigree = *ped_it;

//         for(int f=0; f<pedigree->families.size(); ++f) {

//             vector<personClass*> family = pedigree->families.at(f);
//             personClass* mother = family.at(0);
//             personClass* father = family.at(1);
//             int motherN = mother->n;
//             int fatherN = father->n;

    
//             for(int c=0; c<family.size()-2; ++c) {

//                 personClass* child = family.at(c+2);
//                 int childN = child->n;
//                 int sexIndex = getSexIndex(pedigree,child);
//                 int shadingIndex = _emissionMapping.at(child->typeOfShading);

//                 double total = 0.0;
//                 for(int i=0; i<motherN; ++i) {

//                     double a_i_pq = _getAVal(pedigree,d,f,true,i);
//                     for(int j=0; j<fatherN; ++j) {

//                         double a_j_qp = _getAVal(pedigree,d,f,false,j);

//                         double bProd = 1.0;
//                         double bProdTotal = 1.0;
//                         for(int s=0; s<family.size()-2; ++s) {
                            
//                             personClass* sibling = family.at(s+2);
//                             double b_ij_s = _getBVal(pedigree,d,f,i,j,sibling,s);

//                             bProdTotal *= b_ij_s;
//                             if(s == c) {
//                                 continue;
//                             }
//                             bProd *= b_ij_s;
//                         }

//                         double shouldEqual_b_ij_c = 0.0;
//                         for(int k=0; k<childN; ++k) {

//                             double A_ijk = _transitionProbs.at(sexIndex).at(i).at(j).at(k);
//                             double B_k_c = _emissionProbs.at(sexIndex).at(k).at(shadingIndex);
//                             double mProd = 1.0;
//                             for(auto pair_it=child->mateKids.begin(); pair_it!=child->mateKids.end(); ++pair_it) {

//                                 personClass* mate = pair_it->first;
//                                 int mateN = mate->n;
//                                 personClass* mother_;
//                                 personClass* father_;
//                                 sortMates(child,mate,mother_,father_);
//                                 int newF = getFamNumb(pedigree,mother_,father_);

//                                 double kSum = 0.0;
//                                 for(int k_=0; k_<mateN; ++k_) {

//                                     double w_kk__mc;
//                                     w_kk__mc = _getWVal(pedigree,d,newF,(int)(child == mother),k,k_);
//                                     kSum += w_kk__mc;
//                                 }
//                                 mProd *= kSum;
//                             }

//                             double val = a_i_pq * a_j_qp * A_ijk * B_k_c * mProd * bProd;
//                             _e.at(d).at(f).at(i).at(j).at(c).at(sexIndex).at(k) = val;
//                             total += val;
                            

//                             shouldEqual_b_ij_c += A_ijk * B_k_c * mProd;
//                         }

// ///////////////////////
//                         double real_b_ij_c = _getBVal(pedigree,d,f,i,j,child,c);
//                         if(abs(shouldEqual_b_ij_c-real_b_ij_c) > PRECISION) {
//                             raise(SIGABRT);
//                         }
// ///////////////////////

//                         double shouldEqual_totalBProd = bProd * shouldEqual_b_ij_c;
//                         if(abs(shouldEqual_totalBProd-bProdTotal) > PRECISION) {
//                             raise(SIGABRT);
//                         }

// ///////////////////////
//                         double shouldEqual_w_ij_qp = a_j_qp * bProd * shouldEqual_b_ij_c;
//                         double w_real = _getWVal(pedigree,d,f,true,i,j);
//                         if(abs(shouldEqual_w_ij_qp-w_real) > PRECISION) {
//                             raise(SIGABRT);
//                         }
// ///////////////////////
                        
                        
//                     }
//                 }
//                 for(int i=0; i<motherN; ++i) {
//                     for(int j=0; j<fatherN; ++j) {
//                         double marginalizeSum = 0.0;
//                         for(int k=0; k<childN; ++k) {
//                             _e.at(d).at(f).at(i).at(j).at(c).at(sexIndex).at(k) /= total;
//                             marginalizeSum += _e.at(d).at(f).at(i).at(j).at(c).at(sexIndex).at(k);
//                         }
//                         double compareAgainst = _d.at(d).at(f).at(i).at(j);
//                         if(abs(marginalizeSum-compareAgainst) > PRECISION) {
//                             raise(SIGABRT);
//                         }
//                     }
//                 }
//             }
//         }
//         ++d;
//     }
// }



// void EMPedigreeOptimizer::_updateRootProbs2() {
//     int d = 0;
//     for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {
        
//         int r = 0;
//         for(auto r_it=(*ped_it)->roots.begin(); r_it!=(*ped_it)->roots.end(); ++r_it) {
            
//             personClass* root = *r_it;
//             int rootN = root->n;
//             int rIndex = (*ped_it)->mapToIndexAllPeople.at(root);
            
//             double totalSum = 0.0;
//             for(int i=0; i<rootN; ++i) {
//                 totalSum += _c.at(d).at(rIndex).at(i);
//                 _rootProbs.at(d).at(r).at(i) = _c.at(d).at(rIndex).at(i);
//             }
//             ++r;
            
            
//             if(abs(totalSum-1.0) > PRECISION) {
//                 raise(SIGABRT);
//             }
//         }
//         ++d;
//     }
// }

// void EMPedigreeOptimizer::_updateTransitionProbs2() {
    
//     vector<int> sexToIterate;
//     if(_sexDependent) {
//         sexToIterate = vector<int>({_femaleN,_maleN,_unknownN});
//     }
//     else {
//         sexToIterate = vector<int>({_femaleN});
//     }
    
    
//     for(int i=0; i<_femaleN; ++i) {
//         for(int j=0; j<_maleN; ++j) {
            
//             for(int s=0; s<_transitionProbs.size(); ++s) {
//                 for(int k=0; k<_transitionProbs.at(s).at(i).at(j).size(); ++k) {
//                     _transitionProbs.at(s).at(i).at(j).at(k) = 0;
//                 }
//             }
            
//             double denominator = 0.0;
            
//             int d = 0;
//             for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {
                
//                 for(int f=0; f<(*ped_it)->families.size(); ++f) {
                    
//                     vector<personClass*> currentFam = (*ped_it)->families.at(f);
                    
//                     for(int c=0; c<currentFam.size()-2; ++c) {
                        
//                         double delta_ij_f = _d.at(d).at(f).at(i).at(j);
//                         denominator += delta_ij_f;
                        
//                         personClass* child = currentFam.at(c+2);
//                         int childN = child->n;
//                         int sexOfChild = getSexIndex(*ped_it,child);
                        
//                         for(int k=0; k<childN; ++k) {
//                             double zeta_ijk_f = _e.at(d).at(f).at(i).at(j).at(c).at(sexOfChild).at(k);
//                             _transitionProbs.at(sexOfChild).at(i).at(j).at(k) += zeta_ijk_f;
//                         }
//                     }
//                 }
//                 ++d;
//             }
            
//             double total = 0.0;
//             for(int s=0; s<_transitionProbs.size(); ++s) {
//                 for(int k=0; k<_transitionProbs.at(s).at(i).at(j).size(); ++k) {
//                     _transitionProbs.at(s).at(i).at(j).at(k) /= denominator;
//                     total += _transitionProbs.at(s).at(i).at(j).at(k);
//                 }
//             }
//             if(abs(total-1.0) > pow(10,-10)) {
//                 raise(SIGABRT);
//             }
//         }
        
//     }
// }

// void EMPedigreeOptimizer::_updateEmissionProbs2() {
    
//     vector<int> sexToIterate;
//     if(_sexDependent) {
//         sexToIterate = vector<int>({_femaleN,_maleN,_unknownN});
//     }
//     else {
//         sexToIterate = vector<int>({_femaleN});
//     }
    
//     for(int sex=0; sex<sexToIterate.size(); ++sex) {
        
//         int sexN = sexToIterate.at(sex);
        
//         for(int i=0; i<sexN; ++i) {
            
//             // emission possibilities
//             double sum = 0.0;
//             for(int y=0; y<4; ++y) {
                
//                 _emissionProbs.at(sex).at(i).at(y) = 0.0;
//                 double denominator = 0.0;
                
//                 int d = 0;
//                 for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {
                    
//                     for(auto p_it=(*ped_it)->allPeople.begin(); p_it!=(*ped_it)->allPeople.end(); ++p_it) {
                        
//                         personClass* current = *p_it;
//                         int pIndex = (*ped_it)->mapToIndexAllPeople.at(current);
//                         int sexInner = getSexIndex(*ped_it,current);
//                         int shadingIndex = _emissionMapping.at(current->typeOfShading);
                        
//                         if(sex != sexInner) {
//                             continue;
//                         }
                        
//                         double epsilon_i_p = _c.at(d).at(pIndex).at(i);
//                         denominator += epsilon_i_p;
                        
//                         if(shadingIndex == y) {
//                             _emissionProbs.at(sex).at(i).at(y) += epsilon_i_p;
//                         }
//                     }
//                     ++d;
//                 }
//                 _emissionProbs.at(sex).at(i).at(y) /= denominator;
//                 sum += _emissionProbs.at(sex).at(i).at(y);
//             }
//             if(abs(sum-1.0) > PRECISION) {
//                 raise(SIGABRT);
//             }
//         }
//     }
// }





// void EMPedigreeOptimizer::_eStep2() {
//     _cUpdate();
//     _dUpdate();
//     _eUpdate();
    
//     _checkC();
//     _checkD();
//     _checkE();
// }

// void EMPedigreeOptimizer::_mStep2() {

//     _updateRootProbs2();
//     _updateTransitionProbs2();
//     _updateEmissionProbs2();
// }

// void EMPedigreeOptimizer::_EMStep2() {
//     _eStep2();
//     _mStep2();
// }





