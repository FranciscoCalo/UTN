#include <iostream>
#include <array>
#include <fstream>
#include <string>
using namespace std;
using Cubo=array<array<array<int,12>,3>,4>;	
void mostrar(Cubo&); 
void cargar(Cubo&); 
int mayor(Cubo&,int,int); 
void Mejorvendedor(const Cubo&,int,int); 
int GetPromedio(const Cubo&,int,int);
string nombres(int,int);
string N_regiones(int); 
void estadisticas (Cubo&);
void CrearTXT(Cubo&);

int main()
{	
Cubo total{};	
cargar(total);
mostrar(total);
estadisticas(total);
CrearTXT(total);	
}

void CrearTXT (Cubo&total)
{
	ofstream file3;
	file3.open("Vendedores.txt",ios::out);
	for (int i{};i<4;++i)
 {  
 	file3<<'\n'<<'\t'<<"LA REGION: "<<N_regiones(i)<<'\n';
 	for (int j{};j<3;++j)
 	{
		file3<<'\n'<<nombres(j,i)<<'\n';
 		for (int k{};k<12;++k)
 		{
          file3<<"En el mes: "<<k+1<<" vendio: "<<"$"<<total[i][j][k]<<'\n';
 		}
 	}
 }
}

void mostrar(Cubo&total)
{
ofstream file;
file.open("file.bin",ios::out|ios::binary);
for (int i{};i<4;++i)
 {  
 	cout<<'\n'<<'\t'<<"LA REGION: "<<N_regiones(i)<<'\n';
 	for (int j{};j<3;++j)
 	{
		cout<<'\n'<<nombres(j,i)<<'\n';
 		for (int k{};k<12;++k)
 		{
          cout<<"En el mes: "<<k+1<<" vendio: "<<"$"<<total[i][j][k]<<'\n';
 		}
 	}
 }	
 file.write(reinterpret_cast<char*>(&total),sizeof(total));
 file.close();
}

void cargar(Cubo&total)
{
 ifstream file2;
 file2.open("file.bin",ios::in|ios::binary);
 file2.read(reinterpret_cast<char*>(&total),sizeof(total));
 int v{},m{},r{},importe{};
 for(;cin>>r>>v>>m>>importe;)
 {
	total.at(r-1).at(v-1).at(m-1)+=importe;
 }
 file2.close();
}

int mayorVenta(Cubo&total,int mes,int region)
{
  int max{};
 	for (auto vendedoraux:total.at(region))
    	if(vendedoraux.at(mes)>max) 
    		max=vendedoraux.at(mes);
 return max;
}

void Mejorvendedor (const Cubo&total,int mes,int region)
{
 int posicion{},max{};
 array<int,3> vectoraux{};
 bool repetido=false;
 //calcular maximo, si esta repetido y la posicion del mejor vendedor
 	for (int j{};j<3;j++)
	{
		// if(total.at(region).at(j).at(mes)==max && repetido==false)
		// {
		// 	repetido=true;
		// }
		if(total[region][j][mes]>max)
		{
		    max=total[region][j][mes];
    		posicion=j+1;
			//eliminar posicion
		}	
	}
	//JuntarLosMejores(max)
	for(int k{0};k<3;k++)
	{ 
		if(total[region][k][mes]==max)
		{
		 vectoraux.at(k)=k+1;
		 //contar la cantidad de mejores
		 //repetido=true;
		}
		else vectoraux.at(k)=0;
	}
	//Mostrar_resultado(mejores_vendedores)
	if(repetido==true) //si la cantidad es mayor a 1, esto
	{
	cout<<"Los mejores vendedores del mes fueron: ";
	for(int l{};l<3;l++)
	{
		cout<<nombres(vectoraux.at(l)-1,region)<<" ";
	}
	}
	else // sino esto	
        cout<<"El mejor vendedor del mes fue: "<<nombres(posicion-1,region);
}

int GetPromedio(const Cubo&total,int mes,int region)
{
	int s{};
	for (auto meses:total.at(region))
			s += meses.at(mes);
	return s/total.at(region).size(); 
}

void estadisticas (Cubo&total)
{
for (int i{};i<12;++i)
{
  for (int j{};j<4;++j)
  {
    cout<<'\n'<<"El importe maximo en el mes "<<i+1<<" para la region "<<N_regiones(j)<<" es de: "<<"$"<<mayorVenta(total,i,j)<<'\n';

	Mejorvendedor(total,i,j);

    cout<<'\n'<<"El importe promedio en el mes "<<i+1<<" para la region "<<N_regiones(j)<<" es de: "<<"$"<<GetPromedio(total,i,j)<<'\n';
  }
}
}

string nombres(int vendedor,int region)	
{
	static const array<array<string,3>,4> vendedores{
	{"Agustin", "Dante", "Barza"},
	{"Virna", "Lucas", "Facundo"},
	{"Sebas", "Jose Maria", "Juan Cruz"},
	{"Ame", "Oliver", "Logan"}
	};
   return vendedores.at(vendedor).at(region);
}

string N_regiones(int region)
{
	array<string,4> regiones{"ESTE","OESTE","NORTE","SUR"};
	return regiones.at(region);
}