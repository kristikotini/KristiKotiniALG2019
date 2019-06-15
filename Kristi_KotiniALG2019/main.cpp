#include "List.hpp"
#include "Peme_binare.hpp"
#include "Hash_table.hpp"
#include <fstream>
#include <time.h>
#include <vector>

int main()
{
    
    vector<string> sv;
    int length = 1000000;
    sv.reserve(length);
    fstream file("teksti.txt",ios::in);
    string fjal;
        if (file.is_open())
        {     
        for(int i=0;i<length && file>>fjal;i++){
            sv.push_back(fjal);
        }
    List l(sv[0]);
    Peme_binare p(sv[0]);
    Hash_table h;
    clock_t start, end;
    double cpu_time_used;	
    //  start = clock();
    // cout<<"Programi nisi"<<endl;
    
    //  for(int i=0;i<length;i++)
    //  {
    //      l.kerko_shto(sv[i]);
    //  }
    //  end = clock();
    //  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    //  cout<<endl;
    //  cout<<"Koha exe: "<<cpu_time_used*1000<<" milisekonda"<<endl;
    //  start = clock();
    //  for(int i=0;i<length;i++)
    //  {
    //      p.kerko_shto(sv[i]);
    //  }
    //  end = clock();
    //  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    //  cout<<endl;
    //  cout<<"Koha exe: "<<cpu_time_used*1000<<" milisekonda"<<endl;
    //  start = clock();
    // for(int i=0;i<length;i++)
    // {
    //     h.kerko_shto(sv[i]);
    // }
    // end = clock();
    // cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    // cout<<endl;
    // cout<<"Koha exe: "<<cpu_time_used*1000<<" milisekonda"<<endl;
    // // cout<<l.get_nr_fjalesh()<<endl;
    // // cout<<p.get_nr_fjalesh()<<endl;
    // cout<<h.get_nr_fjalesh()<<endl;
    file.close();
    return 0;
    }
}