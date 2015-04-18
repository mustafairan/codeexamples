#include <iostream>
#include<string>

using namespace std;
class automata
{
    char reached_states[10]= {NULL};
public : void didAccepted()
    {
        int i=0;
        while(reached_states[i]!=NULL)
        {
            if((reached_states[i]=='4') or (reached_states[i]=='8'))
            {
                cout<<"string is accepted";
                return;
            }
            i++;
        }
        cout<<"string is not accepted";
        return;
    }
    void arrayCopy(char a[10],char b[10])
    {
        for(int i=0; i<10; i++)
        {
            a[i]=b[i];
        }

    }
    char * deleteFromArray(char orginal [10] ,char ap)
    {
        cout<<ap<<" is deleted from reached states "<<endl;
        int i=0;
        while(orginal[i]!=NULL)
        {
            if(orginal[i]==ap)
            {
                orginal[i]='0';
            }

            i++;
        }
        int j=0;
        while(orginal[j]!=NULL)
        {
            if(orginal[j]=='0')
            {
                orginal[j]=orginal[i-1];
                orginal[i-1]=NULL;
            }
            j++;
        }


        return orginal;
    }
    void printarray(char * arr)
    {
        int i=0;
        while(arr[i]!=NULL)
        {
            cout<<"reached state number "<<i+1<<" is= "<<arr[i]<<endl;
            i++;
        }
    }
    char * appendToArray(char orginal [10] ,char ap)
    {

        int i=0;
        while (orginal[i]!=NULL)
        {
            if(ap==orginal[i])
            {
                cout<<ap<<" is already in reached states"<<endl;
                return orginal;
            }
            i++;
        }
        cout<<ap<<" is appended to reached states"<<endl;
        orginal[i]=ap;
        return orginal;
    }

    char * transition(char states[10],char input )
    {
        int i=0;//index of states set
        cout<<endl;
        arrayCopy(reached_states,states);

        while(states[i]!=NULL)
        {
            cout<<"evaluated state = "<<states[i];
            cout<<" input= "<<input<<endl;

            if (states[i]=='1')
            {
                if (input=='w')
                {
                    appendToArray( reached_states,'2');
                    appendToArray( reached_states,'1');
                }
                else if (input=='e')
                {
                    appendToArray( reached_states,'5');
                    appendToArray( reached_states,'1');
                }
                else
                {
                    appendToArray( reached_states,'1');
                }
            }
            else if (states[i]=='2')
            {
                if (input=='e')
                {
                    appendToArray( reached_states,'3');
                    deleteFromArray(reached_states,states[i]);//old state is deleted
                }
                else
                {
                    cout<<" passed to null set from state  "<<states[i]<<"";
                    deleteFromArray(states,states[i]);
                    deleteFromArray(reached_states,states[i]);
                }
            }
            else if (states[i]=='3')
            {
                if (input=='b')
                {
                    appendToArray( reached_states,'4');
                    deleteFromArray(reached_states,states[i]);//old state is deleted
                }
                else
                {
                    cout<<" passed to null set from state  "<<states[i]<<"";
                    deleteFromArray(states,states[i]);
                    deleteFromArray(reached_states,states[i]);
                }
            }
            else if (states[i]=='4')
            {
                deleteFromArray(reached_states,states[i]);
            }
            else if (states[i]=='5')
            {
                if (input=='b')
                {
                    appendToArray( reached_states,'6');
                    deleteFromArray(reached_states,states[i]);//old state is deleted
                }

                else
                {
                    cout<<"passed to null set from state  " <<states[i]<<"";
                    deleteFromArray(states,states[i]);
                    deleteFromArray(reached_states,states[i]);
                }
            }
            else if (states[i]=='6')
            {
                if (input=='a')
                {
                    appendToArray( reached_states,'7');
                    deleteFromArray(reached_states,states[i]);//old state is deleted
                }
                else
                {
                    cout<<"passed to null set from state  "<<states[i]<<"";
                    deleteFromArray(states,states[i]);
                    deleteFromArray(reached_states,states[i]);
                }
            }
            else if (states[i]=='7')
            {
                if (input=='y')
                {
                    appendToArray( reached_states,'8');
                    deleteFromArray(reached_states,states[i]);//old state is deleted
                }

                else
                {
                    cout<<"passed to null set from state  "<<states[i]<<"";
                    deleteFromArray(states,states[i]);
                    deleteFromArray(reached_states,states[i]);
                }
            }
            else if (states[i]=='8')
            {
                deleteFromArray(reached_states,states[i]);
            }
           

            i++;

        }
        arrayCopy(states,reached_states);
        return  states;
    }

public:
    void send(string str)
    {
        char states[10]= {NULL};

        states[0]='1';//initiated with start state


        for (int i=0; i<=((str.length())-1); i++)
        {
            cout<<endl;
            cout<<"transition function will be called for input "<<str[i] <<""<<endl;



            printarray(transition(states,str[i]));


        }
    }
};
int main()
{
    string stri;
    cout << "enter you word: " << endl;
    cin>>stri;
    automata obje;
    obje.send(stri);
    obje.didAccepted();
    return 0;
}
 
