void Client::getGradeFromKeyboard(){
    string NJ;
    int level;
    cout<<"����������꼶��"<<endl;
    std::cin>>NJ;
    if(NJ == "һ�꼶" || NJ == "���꼶") {
        level=1;
    } else if(NJ == "���꼶" || NJ == "���꼶") {
        level=2;
    } else if(NJ == "���꼶" || NJ == "���꼶") {
        level=3;
    }
    server.setGrade(level);
}

void Client::printProblem() {
    std::cout<<server.getproblem()<<"=?"<<std::endl;
}

string Client::getAnsFormKeyboard() {
    string ans;
    std::cin>>ans;
    return ans;
}

int Client::getProCntFromKeyboard() {
	std::cout<<"��������Ŀ����"<<std::endl;
    std::cin>>proCnt;
}

void Client::printEndofPro(){
    if (wrongCnt==0) {
        std::cout<<"������ȫ����ȷ��̫���ˣ�"<<std::endl;
    } else {
        std::cout<<"����������"<<wrongCnt<<"��Ŷ"<<std::endl;
    }
}

Client::Client(){
    int proCnt=0;
    int wrongCnt=0;
}

void Client::start(){
    int i;
    getGradeFromKeyboard();
    getProCntFromKeyboard();
    
    for(i=0;i<proCnt;i++){
        printProblem();
        if(!server.check(getAnsFormKeyboard())){
            wrongCnt++;
        }
    }
    printEndofPro();
}
