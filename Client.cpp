#include <bits/stdc++.h>

void Client::getGradeFromKeyboard(){
    string NJ;
    int level;
    std::cin>>NJ;
    if(strcmp(NJ,"一年级")==0 || strcmp(NJ,"二年级")==0){
        level=1;
    } else if(strcmp(NJ,"三年级")==0 || strcmp(NJ,"四年级")==0){
        level=2;
    } else if(strcmp(NJ,"五年级")==0 || strcmp(NJ,"六年级")==0){
        level=3;
    }
    server->setGrade(int level);
}

void Client::printProblem(){
    std::cout<<server->getproblem();
}

string Client::getAnsFormKeyboard(){
    string ans;
    std::cin>>ans;
    return ans;
}

int Client::getProCntFromKeyboard(){
    std::cin>>proCnt;
}

void Client::printEndofPro(){
    if(correctFormKeyboarCnt==0){
        std::cout<<"全部正确";
    } else {
        std::cout<<"有"<<correctFormKeyboarCnt<<"题错误"<<endl;
    }
    
}

Client::Client(){
    int proCnt=0;
    int correctFormKeyboarCnt=0;
}

void Client::start(){
    int i;
    getGradeFromKeyboard();
    getProCntFromKeyboard();
    
    for(i=0;i<proCnt;i++){
        printProblem();
        if(!server->check(getAnsFormKeyboard())){
            correctFormKeyboarCnt++;
        }
    }
    printEndofPro();
}
