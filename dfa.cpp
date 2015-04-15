#include <iostream>

using namespace std;


class automata{

char state='0';// baslangic state i atandi

public : int didAccepted(){
    if ((state=='7') or (state=='3')){
        cout<<"string kabul edildi";
        return 1;
    }
    else {
        cout<<"string kabul edilmedi";
        return 0;
        }
}

char transition(char input){

    int i=0;

    cout<<"degerlendirilen state = "<<state;
    cout<<" input= "<<input<<endl;

        if (state=='0'){

            if ((input=='w') ) {state ='1';}
            else if (input=='e'){state ='4';}
            else{state ='0';}
            }
        else if (state=='1'){

           if ((input=='w') ){state ='1';}
           else  if ((input=='e') ){state ='2';}
           else{state ='0';}
             }
        else if (state=='2'){

            if ((input=='w')){state ='1';}
            else if ((input=='e')){state ='4';}
            else if ((input=='b')){state ='3';}
            else{state ='0';}
            }
        else if (state=='3'){

            if ((input=='w') ){state ='1';}
            else if ((input=='a') ){state ='6';}
            else if ((input=='e') ){state ='4';}
            else{state ='0';}
            }
        else if (state=='4'){

            if ((input=='b')){state ='5';}
            else if ((input=='w')){state ='1';}
            else if ((input=='e')){state ='4';}
            else{state ='0';}
            }
        else if (state=='5'){

           if ((input=='a') ){state ='6';}
           else if ((input=='e') ){state ='4';}
           else if ((input=='w') ){state ='1';}
           else{state ='0';}
            }
        else if (state=='6'){

            if ((input=='e')){state ='4';}
            else if ((input=='w')){state ='1';}
            else if ((input=='y')){state ='h';}
            else{state ='0';}
            }
        else if (state=='7'){

            if ((input=='e')){state ='4';}
            else if ((input=='w')){state ='1';}
            else{state ='0';}
            }

        i++;

return  state;

}
public: void send (string str){
    int i=0;
    while (str[i]!=NULL){
        transition(str[i]);
        i++;
    }
}
};

int main()
{
    string str;
    cout<<"sozcuk?: ";
    cin >>str;
    automata object;
    object.send (str);
    object.didAccepted();
    return 0;
}
