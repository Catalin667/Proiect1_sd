#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<chrono>
#include<cmath>
#include<random>
#include<algorithm >
 using namespace std;
volatile int sink;
 

bool  descr(long a, long b)
{




    return a > b;
}
 
  
 
void generare_numere(long  dimensiune_vector, long  v[], long  interval) {

    std::random_device rd;   
    std::mt19937 gen(rd());  
    std::uniform_int_distribution<> distrib(0, interval-1);

    for (long i = 0; i < dimensiune_vector; ++i)
        v[i] = distrib(gen);

}

void vector_constant(long  dimensiune_vector, long  v[], long  interval) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, interval - 1);
    long x= distrib(gen);
    for (long i = 0; i < dimensiune_vector; ++i)
        v[i] = x;

}


void copiere_vector(long  dimensiune_vector, long  v[], long  vector[])
{
    
    for (long i = 0; i < dimensiune_vector; i++)
        vector[i] = v[i];

}

void afisare_vector(long  dimensiune_vector, long  v[])
{

    for (long  i = 0; i < dimensiune_vector; i++)
    {
        cout << v[i] << " ";
        
    }
    
}
 

int verificare_sortare(long vector_initial[], long dimensiune_vector, long vector_dupa_sortare[])
{
   
    for (long i = 0; i < dimensiune_vector-1; i++)
    
       if(vector_initial[i]!=vector_dupa_sortare[i])
            return -1;
    return 1;
    
}
 

void Bubble_Sort(long  dimensiune_vector, long v[]) {
     
         for (long i = 0; i <= dimensiune_vector - 1; i++)
            for (long j = 0; j < dimensiune_vector; j++)
                 if (v[i] < v[j]) {
                     long  aux = v[i];
                     v[i] = v[j];
                     v[j] = aux;
                 }
     
    
   
}

void Counting_Sort(long  dimensiune_vector, long  v[] , long  dimensiune){
    long  nr_byte = (dimensiune + 1) * 4 + (dimensiune_vector) * 4;
    if(nr_byte> 4000000000 || dimensiune_vector>=1000000000)
        cout << "Nu se poate sorta, deoarece depaseste 4GB sau dimensiunea vectorului este prea mare si dureaza foarte mult :(((("<<endl;
    else
    {
        long  max = 0;
        long * fr = new long[dimensiune+1];

        for (long  i = 0; i <= dimensiune; i++)
            fr[i] = 0;
        for (long  i = 0; i < dimensiune_vector; i++)
        {
            fr[v[i]]++;
            if (v[i] > max)
                max = v[i];
        }
        long k = 0;
        for (long i = 0; i <= max; i++)
        {
            for (long j = 1; j <= fr[i]; j++)
                v[k++] = i;
        }
        delete []fr;
    }
}
void Interclasare(long st, long mij, long dr, long vector[], long aux[]) {
    long i = st, j = mij + 1, k=st;
    while (i <= mij && j <= dr)
    {
        if (vector[i] <= vector[j])
        {
            aux[k] = vector[i];
            k++;
            i++;
        }
        else
        {
            aux[k] = vector[j];
            k++;
            j++;
        }
    }
        while(i<=mij)
        {
            aux[k] = vector[i];
            i++;
            k++;
        }
        while(j<=dr)
        {
            aux[k] = vector[j];
            j++;
            k++;
            
        }
        for (i = st; i < k; i++)
            vector[i] = aux[i];

}
 
void Merge_Sort(long st, long dr, long vector[], long aux[]) 
{
    
    
        if (st < dr)
        {
            long mij = (dr + st) / 2;
            Merge_Sort(st, mij, vector, aux);
            Merge_Sort(mij + 1, dr, vector, aux);
            Interclasare(st, mij, dr, vector, aux);

        }
    
    

}
int partitie(long st, long dr, long v[]) {
    long pivot = v[dr];
    long i = st-1;
    for (long j=st; j <= dr - 1; j++)
    {
        if (v[j] < pivot)
        {
            i++;
            long aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }
    long aux = v[i + 1];
    v[i + 1] = v[dr];
    v[dr] = aux;
    return (i + 1);


}

void Quick_Sort1(long st, long dr, long v[])
{
    
   
        if (st < dr) {
            long pivot;
            pivot = partitie(st, dr, v);
            Quick_Sort1(st, pivot - 1, v);
            Quick_Sort1(pivot + 1, dr, v);
        }
     
}
 
int partitie_mediana(long st, long dr, long v[]) {
    long mij = (st + dr) / 2, aux,pivot;
    if (v[st] > v[mij])
    {
        aux = v[st];
        v[st] = v[mij];
        v[mij] = aux;
    }
    if (v[mij] > v[dr])
    {
        aux = v[mij];
        v[mij] = v[dr];
        v[dr] = aux;
    }
    if (v[st] > v[mij])
    {
        aux = v[st];
        v[st] = v[mij];
        v[mij] = aux;
    }
    pivot = v[mij];
    
    aux = v[dr];
    v[dr] = v[mij];
    v[mij] = aux;

    long i = st - 1;
    for (long j = st; j <= dr - 1; j++)
    {
        if (v[j] < pivot)
        {
            i++;
            long aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }
     aux = v[i + 1];
    v[i + 1] = v[dr];
    v[dr] = aux;
    return (i + 1);
}
void Quick_Sort2(long st, long dr, long v[])
{


    if (st < dr) {
        long pivot;
        pivot = partitie_mediana(st, dr, v);
        Quick_Sort2(st, pivot - 1, v);
        Quick_Sort2(pivot + 1, dr, v);
    }

}
int afla_max(long dimensiune_vector, long v[]) {
    long max = v[0];
    for (long i = 1; i < dimensiune_vector; i++)
        if (v[i] > max)
            max = v[i];
    return max;
 }
void sortare_dupa_cifre(long dimensiune_vector, long exponent, long v[]){
    long* aux = new long[dimensiune_vector];
    int fr[10] = { 0 };
    for (long i = 0; i < dimensiune_vector; i++)
        fr[(v[i] / exponent) % 10]++;
    for (int i = 1; i < 10; i++)
        fr[i] += fr[i - 1];
    for (long i = dimensiune_vector - 1; i >= 0; i--)
    {
        aux[fr[(v[i] / exponent) % 10] - 1] = v[i];
        fr[(v[i] / exponent) % 10]--;
    }
    for (long i = 0; i < dimensiune_vector; i++)
        v[i] = aux[i];
    delete[]aux;
}
void Radix_Sort(long dimensiune_vector, long v[])
{
    
        long max = afla_max(dimensiune_vector, v);

        for (long exponent = 1; max / exponent > 0; exponent *= 10)
            sortare_dupa_cifre(dimensiune_vector, exponent, v);
    
}
 

int main()
{
    
         
        long   vector_size;
        long  nr_max;
        
            int ex = 0,exceptie=0;
            while (ex == 0) {
                
                 cout << "Introduceti dimensiunea vectorului: ";
                 cin >> vector_size;
                   
                    if (vector_size < 1000000000)
                    ex=1;
                
                    else
                    {
                        cout << "Dimensiunea vectorului este prea mare, incearca o noua valoare;" << endl;
                        ex = 0;
                    }
            }
        
        long* v = new long[vector_size];
        long* vector = new  long[vector_size];
        long* vector_sortat = new long[vector_size];
        
        int alegere;
        bool ok = true;
        while (ok != false) {
            cout << "Apasa 1 pentru a se genera un vector automat; " << endl;
            cout << "Apasa 2 pentru a se genera un vector constant; " << endl;
            cout << "Apasa 3 pentru un vector sortat crescator; " << endl;
            cout << "Apasa 4 pentru un vector sortat descrescator; " << endl;
            cout << "Apasa 5 pentru un vector aproape sortat crsecator; " << endl;
            cout << "Apasa 6 pentru un vector aproape sortat descrescator; " << endl;
            cout << "Apasa 7 pentru iesire; " << endl;
            cout << "Optiunea dumneavoastra este:";
            cin >> alegere;
            cout << endl;
            switch (alegere) {
            case 1:
            {cout << "Introduceti capatul drept al intervalului:";
            cin >> nr_max;
            generare_numere(vector_size, v, nr_max);
            ok = false;
            break;
            }



            case 2:
            {   cout << "Introduceti capatul drept al intervalului:";
            cin >> nr_max;
            vector_constant(vector_size, v, nr_max);
            if (vector_size >= 1000)
                exceptie = 1;
            ok = false;
            break; }
            case 3: {cout << "Introduceti capatul drept al intervalului:";
                     cin >> nr_max;
                     generare_numere(vector_size, v, nr_max);
                     sort(v, v + vector_size);
                     exceptie = 1;
                     ok = false;
                     break;
            }
            case 4: {cout << "Introduceti capatul drept al intervalului:";
                cin >> nr_max;
                generare_numere(vector_size, v, nr_max);
                sort(v, v + vector_size,descr);
                exceptie = 1;
                
                ok = false;
                break;
            }
            case 5: {
                cout << "Introduceti capatul drept al intervalului:";
                cin >> nr_max;
                generare_numere(vector_size, v, nr_max);
                sort(v, v + vector_size/2);

                ok = false;
                break;
            }
            case 6: {
                cout << "Introduceti capatul drept al intervalului:";
                cin >> nr_max;
                generare_numere(vector_size, v, nr_max);
                sort(v, v + vector_size/2, descr);
                ok = false;
                break;
            }
            case 7:
            {
                return 0;
            }}
            
        }


        copiere_vector(vector_size, v, vector);
        copiere_vector(vector_size, v, vector_sortat);

        cout << "Sortare nativa in limbajul C++:";
        auto start0 = std::chrono::steady_clock::now();
        sort(vector_sortat, vector_sortat + vector_size);
        auto stop0 = std::chrono::steady_clock::now();
        std::chrono::duration<long double> diff0 = stop0 - start0;
        cout << "Timpul de executie al sortarii native in C++ este :" << " " << diff0.count() << " " << "s;" << endl;
        cout << endl;


       

        cout << " 1.Bubble Sort:" << endl;
        if (vector_size <= 9999)
        {
            auto start = std::chrono::steady_clock::now();
            Bubble_Sort(vector_size, vector);
            auto stop = std::chrono::steady_clock::now();
            std::chrono::duration<long double> diff = stop - start;
            if (verificare_sortare(vector_sortat, vector_size, vector) == 1 )
            {

                cout << "Sorteaza " << vector_size << " numere;" << endl;
                cout << "Numarul maxim este :" << nr_max << ";" << endl;
                cout << "Timpul de executie al algoritmului este :" << " " << diff.count() << " " << "s;" << endl;
                cout << "CORECT!!!" << endl;

            }
            else
              cout << "Incorect! :(((" << endl;

        }
        else
            cout << "Nu se poate folosi Bubble Sort, deoarece dureaza prea mult; :(((" << endl;
        cout << endl;
        cout << endl;
        copiere_vector(vector_size, v, vector);





        cout << " 2.Counting Sort: " << endl;
        auto start1 = std::chrono::steady_clock::now();
        Counting_Sort(vector_size, vector, nr_max);
        auto stop1 = std::chrono::steady_clock::now();
        std::chrono::duration<long double> diff1 = stop1 - start1;
        if (verificare_sortare(vector_sortat, vector_size, vector) == 1)
        {


            cout << "Sorteaza " << vector_size << " numere;" << endl;
            cout << "Numarul maxim este : " << nr_max << ";" << endl;
            cout << "Timpul de executie al algoritmului este :" << " " << diff1.count() << " " << "s;" << endl;
            cout << "CORECT!!!" << endl;
        }
        else
            cout << "INCORECT!!! :(((" << endl;
        cout << endl;
        cout << endl;


        copiere_vector(vector_size, v, vector);





        long* aux = new long[vector_size];
        auto start2 = std::chrono::steady_clock::now();
        Merge_Sort(0, vector_size - 1, vector, aux);
        auto stop2 = std::chrono::steady_clock::now();
        std::chrono::duration<long double> diff2 = stop2 - start2;
        cout << " 3.Merge Sort:" << endl;
        if (verificare_sortare(vector_sortat, vector_size, vector) == 1)
        {


            cout << "Sorteaza " << vector_size << " numere;" << endl;
            cout << "Numarul maxim este : " << nr_max << ";" << endl;
            cout << "Timpul de executare:" << diff2.count() << " " << "s;" << endl;
            cout << "CORECT!!!" << endl;
        }
        else
            cout << " INCORECT!! :(((" << endl;
        cout << endl;
        cout << endl;

        copiere_vector(vector_size, v, vector);

        cout << " 4.Quick Sort:" << endl;
        if (exceptie == 0 )
        {
          
            cout << "  4.1. Pivot = ultimul element;" << endl;
            auto  start3 = std::chrono::steady_clock::now();
            Quick_Sort1(0, vector_size - 1, vector);
            auto stop3 = std::chrono::steady_clock::now();
            std::chrono::duration<long double> diff3 = stop3 - start3;
            if (verificare_sortare(vector_sortat, vector_size, vector) == 1)
            {
                cout << "Sorteaza " << vector_size << " numere;" << endl;
                cout << "Numarul maxim este : " << nr_max << ";" << endl;
                cout << "Timpul de executare:" << diff3.count() << " " << "s;" << endl;
                cout << "CORECT!!!" << endl;
            }
            else
            {
                cout << " INCORECT!! :(((" << endl;
                cout << "Nu se poate folosi Quick Sort, deoarece dimensiunea vectorului este prea mare si dureaza prea mult; :(((" << endl;
            }
            cout << endl;
            cout << endl;

            copiere_vector(vector_size, v, vector);


            cout << "  4.2.Pivot = mediana din 3;" << endl;
            auto  start4 = std::chrono::steady_clock::now();
            Quick_Sort2(0, vector_size - 1, vector);
            auto stop4 = std::chrono::steady_clock::now();
            std::chrono::duration<long double> diff4 = stop4 - start4;
            if (verificare_sortare(vector_sortat, vector_size, vector) == 1)
            {
                cout << "Sorteaza " << vector_size << " numere;" << endl;
                cout << "Numarul maxim este : " << nr_max << ";" << endl;
                cout << "Timpul de executare:" << diff4.count() << " " << "s;" << endl;
                cout << "CORECT!!!" << endl;
            }
            else
            {
                cout << " INCORECT!! :(((" << endl;
                cout << "Nu se poate folosi Quick Sort, deoarece dimensiunea vectorului este prea mare si dureaza prea mult; :(((" << endl;
            }
            cout << endl;
            cout << endl;
        }
        else
        {
            cout << "Nu se poate folosi Quick Sort pentru vector constant/sortat cresc/sortat descrescator pentru aceasta dimensiune; :(((" << endl;
            cout << endl;
        }


        copiere_vector(vector_size, v, vector);


        cout << " 5.Radix Sort:" << endl;
        auto  start5 = std::chrono::steady_clock::now();
        Radix_Sort(vector_size, vector);
        auto stop5 = std::chrono::steady_clock::now();
        std::chrono::duration<long double> diff5 = stop5 - start5;
        if (verificare_sortare(vector_sortat, vector_size, vector) == 1)
        {
            cout << "Sorteaza " << vector_size << " numere;" << endl;
            cout << "Numarul maxim este : " << nr_max << ";" << endl;
            cout << "Timpul de executare:" << diff5.count() << " " << "s;" << endl;
            cout << "CORECT!!!" << endl;
        }
        else
            cout << " INCORECT!! :(((" << endl;

        copiere_vector(vector_size, v, vector);
        delete[]vector_sortat;
        delete[]aux;
        delete[]v;
        delete[]vector;
        
       
    return 0;
}
