//DIVIDE Y VENCERAS EJERCICIO 8
//FILA 3
#include<iostream>
#include<vector>

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
int KSimo (vector<int> V, int k)
{
    k--; //Se resta uno pues los indices empiezan desde 0 y no existe el 0-simo en un lenguaje natural
    vector<int> sorted = mergeSort (V);
    for (int i=0;i<sorted.size();i++)
    {
        if (sorted[i]==sorted[i+1] && i != sorted.size()-1)
        {
            k++;
        }
        if (i == k)
        {
            return sorted[i];
        }
    }
}
int main()
{
    vector<int> V2 = { 10, 2, 2, 1, 6, 3, 3, 4, 7, 9 };
    int k=4;
    cout<< "El "<<k<<"-simo menor valor es: "<<KSimo(V2,k);
}