#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
void Histogram(int arr[500],int sent)
{
        char symbol;
        cout<<"Enter a symbol of your choice for histogram: "<<endl;
        cin>>symbol;
        cout<<"\n\tHISTOGRAM";
        cout<<"\n=====================";
        cout<<"\n\tSentence\tWords";
        for(int i=0;i<sent;i++)
        {
                cout<<"\n"<<i+1<<"\t";
                for(int j=0;j<arr[i];j++)
                {
                        cout<<symbol<<" ";
                }
        }
        cout<<endl;
}
int main()
{
        //fstream file;
        char filename[50];
        string lines;
        int i=0,sent=0,word=0,arr[500]={0};
        cout<<"Enter a filename: ";
        cin>>filename;
        fstream file (filename);
        if(!file)
        {     
            cout<<" File not exist ";
            return 0;                                                                                                                                                                                                                                    cout<<"\nPlease enter a filename!!!"<<endl;
        }
        else
        {
                while(!file.eof())
                {
                        getline(file,lines);
                        for(int i=0;i<lines.length();i++)
                        {
                                cout<<lines[i];
                                if(lines[i]==' ' || lines[i]=='.')
                                {
                                        word++;
                                        arr[sent]=word;
                                }
                                if(lines[i]=='.' || lines[i]=='\n')
                                {
                                        sent++;
                                        word=0;
                                }
                        }
                }
                Histogram(arr,sent);
        }
        file.close();
        return 0;
}
