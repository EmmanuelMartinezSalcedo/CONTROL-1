//ALGORITMOS VORACES EJERCICIO 1A
//FILA 3
#include<iostream>
#include<vector>
#include<utility>

using namespace std;
vector<int> combinar(vector<int> a, vector<int> b)
{
    vector<int> c;
    int i = 0;
    int j = 0;
    while (a.size() > i && b.size() > j)
    {
        if (a[i] < b[j])
        {
            c.push_back(a[i]);
            i++;
        }
        else
        {
            c.push_back(b[j]);
            j++;
        }
    }
    while (a.size() > i)
    {
        c.push_back(a[i]);
        i++;
    }
    while (b.size() > j)
    {
        c.push_back(b[j]);
        j++;
    }
    return c;
}

vector<int> mergeSort(vector<int> V)
{
    int size = V.size();
    if (size == 1)
    {
        return V;
    }
    int mid = size / 2;
    vector<int> izq(V.begin(), V.begin() + mid);
    vector<int> der(V.begin() + mid, V.end());
    izq = mergeSort(izq);
    der = mergeSort(der);
    return combinar(izq, der);
}
pair<vector<int>,int> MaxCont(vector<int> V, int capacidad)
{
    int pesoACT=0;
    vector<int> Solucion;
    vector<int> Sort = mergeSort(V);
    for (int i=0;i<Sort.size();i++)
    {
        if (pesoACT+Sort[i] > capacidad)
        {
            break;
        }
        Solucion.push_back(Sort[i]);
        pesoACT=pesoACT+Sort[i];
    }
    return {Solucion,pesoACT};
}
int main()
{

    vector<int> pesos={1,5,3,2,11,10};
    pair<vector<int>,int> Maximo = MaxCont(pesos,25); //Recibe vector de pesos y capacidad del buque
    for (int i=0;i<Maximo.first.size();i++)
    {
        cout<<"Se cargo el contenedor de peso: "<<Maximo.first[i]<<endl;
    }
    cout<<"Total cargado: "<<Maximo.second;
   
}