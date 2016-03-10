#include<iostream>

using namespace std;

int main()
{
    string k; int f,s,a;
    bool fop=false;
    getline(cin,k);
    cout<<k<<"\n";
    for(int i=0;i<k.length();i++)
    {

        if(k.at(i)>=48&&k.at(i)<=57)
        {
            if(!fop)
            {
                //cout<<k.at(i)<<"\n";
                f=(int(k.at(i))-48);
              //cout<<"firt init "<<f<<"\n";
                i++;
                while(int(k.at(i))!=32)
                {

                    f=(f*10)+(int(k.at(i))-48);
                //    cout<<f<<"loop \n";
                    i++;
                }
                fop=true;
                //cout<<f<<"\n";
            }
            else{
                s=(int(k.at(i))-48);
            //cout<<"second init : "<<s<<"\n";
            i++;

                while(int(k.at(i))!=32)
                    {
                        //i++;
                        s=(s*10)+(int(k.at(i))-48);
              //          cout<<s<<" loop \n";
                        i++;
                    }
                //    cout<<s<<"\n";

            }
            //cout<<f<<" "<<s<<"\n";
            }


        else if(k.at(i)=='*')
        {
            //cout<<" multi \n";
            //cout<<f<<" "<<s<<"\n";
            f=f*s;
            //cout<<f;

        }
        else if(k.at(i)=='/')
        {
            //cout<<" div \n";
            f=f/s;
        }
        else if(k.at(i)=='+')
        {
            //out<<" add \n";

            f=f+s;
        }
        else if(k.at(i)=='-')
        {
            //cout<<" sub \n";
            f=f-s;
        }



}
cout<<f;
    return 0;
    }
