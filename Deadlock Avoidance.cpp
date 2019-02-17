#include<iostream>
#include<ctime>
#define MAX_A 10
#define MAX_B 8
#define MAX_C 12

using namespace std;

class Process{
    int req[3],allocated[3],need[3];
    bool finished;
public:
    void setReq(int re1,int re2,int re3){
        req[0]=re1;
        req[1]=re2;
        req[2]=re3;
    }
    int* getAlloc(){
        cout<< "Allocation: " << allocated[0] << " " << allocated[1]<< " " <<allocated[2]<<endl;
        return(allocated);
    }
    void setAlloc(int allocation1,int allocation2, int allocation3){
        allocated[0]=allocation1;
        allocated[1]=allocation2;
        allocated[2]=allocation3;
    }
    void calcNeed(){
        for(int i=0;i<3;i++){
            need[i]=req[i]-allocated[i];
        }
    }
    int* getNeed(){
        cout<< "Need " << need[0] << " " << need[1]<< " " <<need[2]<<endl;
        return(&need[0]);
    }
    int setFinish(){
            finished=true;
        return 0;
    }
    bool getFinish(){
        return(finished);
    }
    Process(){
        finished=false;
    }

};

class Resource{
    int available;
    public:
    int use(int a){
        available-=a;
        return(a);
    }
    void addAvail(int a){
        available+=a;
    }
    int getAvail(){
        return(available);
    }
    Resource(int a){
        available=a;
    }
};

int main(){
    int i, numProcess, resAreq, resBreq, resCreq;
    int aAlloc,bAlloc,cAlloc,seqOfExec[numProcess];
    int a, resAAvail, resBavail, resCavail;
    int *iPro, *iProAlloc, countFinPro=0;
    bool alldone=false;
    srand((unsigned)time(NULL));
    Resource resA(MAX_A), resB(MAX_B), resC(MAX_C);
    cout<< "How many processes? ";
    cin>> numProcess;
    Process pro[numProcess];
    for(i=0;i<numProcess;i++){
        if(i+1==1){
            cout << "Enter max required resource for 1st process: " <<endl;
            cout <<"A: ";
            cin>> resAreq;
            cout <<"B: ";
            cin>> resBreq;
            cout <<"C: ";
            cin>> resCreq;
        }else if(i+1==2){
            cout << "Enter max required resource for 2nd process: " <<endl;
            cout <<"A: ";
            cin>> resAreq;
            cout <<"B: ";
            cin>> resBreq;
            cout <<"C: ";
            cin>> resCreq;
        }
        else if(i+1==3){
            cout << "Enter max required resource for 3rd process: "<<endl;
            cout <<"A: ";
            cin>> resAreq;
            cout <<"B: ";
            cin>> resBreq;
            cout <<"C: ";
            cin>> resCreq;
        }else{
            cout << "Enter max required resource for " << i+1<< "th process: " <<endl;
            cout <<"A: ";
            cin>> resAreq;
            cout <<"B: ";
            cin>> resBreq;
            cout <<"C: "; 
            cin>> resCreq;
        }
        pro[i].setReq(resAreq,resBreq,resCreq);
        if(resA.getAvail()<resAreq)
            aAlloc=rand()%(resA.getAvail()+1);
        else if(resA.getAvail()>resAreq)
            aAlloc=rand()%(resAreq+1);
        else aAlloc=0;
        if(resB.getAvail()<resBreq)
            aAlloc=rand()%(resB.getAvail()+1);
        else if(resB.getAvail()>resBreq)
            bAlloc=rand()%(resBreq+1);
        else bAlloc=0;
        if(resC.getAvail()<resCreq)
            cAlloc=rand()%(resC.getAvail()+1);
        else if(resC.getAvail()>resCreq)
            cAlloc=(rand()%resCreq+1);
        else cAlloc=0;
        pro[i].setAlloc(resA.use(aAlloc),resB.use(bAlloc),resC.use(cAlloc));
        cout << "Process " << i+1 << " assigned " << aAlloc <<" of A, " <<bAlloc<< " of B, " << cAlloc << " of C."<<endl;

    }
    a=0;
    for(i=0;i<numProcess;i++)
        pro[i].calcNeed();
    while(!alldone){
        if(a==20)
            break;
        for(int j=0,i=0;i<numProcess;i++){
            cout<< "Process " << i;
            iPro=pro[i].getNeed();
            iProAlloc=pro[i].getAlloc();
            if(iPro[0]<=resA.getAvail() && iPro[1]<=resB.getAvail() && iPro[2]<=resC.getAvail() && !pro[i].getFinish()){
                pro[i].setFinish();
                seqOfExec[j]=i;
                j++;
                resA.addAvail(iProAlloc[0]);
                resB.addAvail(iProAlloc[1]);
                resC.addAvail(iProAlloc[2]);
            }
        }
        for(i=0;i<numProcess;i++){
            if(pro[i].getFinish())
                countFinPro++;
        }
        if(countFinPro==numProcess)
                alldone=true;
        else
            countFinPro=0;
        a++;    
    }
    if(!alldone){
        cout<< "The processes have no possible safe sequence";
        return 0;
    }
    else{
        cout << "The safe sequence is:"<< endl;
        for (i=0;i<numProcess;i++)
            cout <<"Process " << seqOfExec[i] <<"\t";
    }
    return 0;
}