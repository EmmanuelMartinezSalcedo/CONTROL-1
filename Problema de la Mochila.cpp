//MOCHILA
//FILA 3
#include<iostream>
#include<vector>
#include<tuple>

using namespace std;


vector<tuple<int,float>> combinar(vector<tuple<int,float>> a, vector<tuple<int,float>> b)
{
    vector<tuple<int,float>> c;
    int i = 0;
    int j = 0;
    while (a.size() > i && b.size() > j)
    {
        if (get<1>(a[i]) > get<1>(b[j])) //MergeSort modificado para que ordene de mayor a menor
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

vector<tuple<int,float>> mergeSort(vector<tuple<int,float>> V)
{
    int size = V.size();
    if (size == 1)
    {
        return V;
    }
    int mid = size / 2;
    vector<tuple<int,float>> izq(V.begin(), V.begin() + mid);
    vector<tuple<int,float>> der(V.begin() + mid, V.end());
    izq = mergeSort(izq);
    der = mergeSort(der);
    return combinar(izq, der);
}
vector<int> Mochila(int M, vector<int> b, vector<int> p)
{
    vector<int> X;
    for (int i = 0; i < b.size(); i++)
    {
        X.push_back(0);
    }
    int pesoAct = 0;
    vector<tuple<int,float>> bp_relation;
    for (int i = 0; i < b.size(); i++)
    {
        float aux = static_cast<float>(b[i]) / p[i];
        bp_relation.push_back(make_tuple(i, aux));
    }
    bp_relation = mergeSort(bp_relation); //creando vector de tuplas que contiene int (indice) y float (relaciones b/p)
    int i = 0;
    while (pesoAct < M) //Insertando mejores objetos mientras el peso lo permite
    {
        int currentIndex = get<0>(bp_relation[i]); //Los objetos estan desordenados en bp_relation pero sus indices originales se guardaron
        if (pesoAct + p[currentIndex] <= M)
        {
            X[currentIndex] = 1;
            pesoAct = pesoAct + p[currentIndex];
        }
        else
        {
            X[currentIndex] = (M - pesoAct) / p[currentIndex];
            pesoAct = M;
        }
        i++;
    }
    return X; //El vector tiene 0s y 1s, 0 representa los objetos que no se añadieron y 1 los objetos que si se añadieron
}
int main()
{
    //El problema pide llenar la mochila con los mejores objetos relacion beneficio/peso
    vector<int> p = { 10,3,3,4 };
    vector<int> b = { 10,9,9,9 };
    int M = 15;
    vector<int> solution = Mochila(M, b, p); //Recibe la capacidad de la mochila, vector de beneficios y vector de pesos
    for (int i = 0; i < solution.size(); i++)
    {
        if (solution[i]==1)
        {
            cout<<"Se añadio el objeto: "<<i<<endl;
        }
        else
        {
            cout<<"No se añadio el objeto: "<<i<<endl;
        }
    }
}