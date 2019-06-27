#include <iostream>
#include <string.h>
#include <iomanip>
#include <conio.h>
#define Max 10
using namespace std;

//inisialisasi struct buku
struct Buku
{
  int ID;
  string Judul;
  string Penulis;
  string Penerbit;
  string Tanggal;
};

//?????
struct Temp
{
  int ID;
  string Judul;
  string Penulis;
  string Penerbit;
  string Tanggal;
};

//????
void border()
{
  for(int i = 0; i < 99; i++)
  {
    cout<<"=";
  }
  cout<<endl;
}


void linemid()
{
  for(int i = 0; i < 99; i++)
  {
    cout<<"-";
  }
  cout<<endl;
} 


//struct of array untuk queue
struct queue
{
  struct Buku Book[Max];
  struct Temp temp[Max];
  int awal, akhir;
} qu;

//?????
void init()
{
  qu.awal = 0;
  qu.akhir = 0;
}


bool empty()
{
  if(qu.akhir == -1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

bool full()
{
  if(qu.akhir == Max-1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}



void add(int ID, string Judul, string Penulis, string Penerbit, string Tanggal)
{
  if(!full())
  {
    qu.Book[qu.akhir].ID = ID;
    qu.Book[qu.akhir].Judul = Judul;
    qu.Book[qu.akhir].Penulis = Penulis;
    qu.Book[qu.akhir].Penerbit = Penerbit;
    qu.Book[qu.akhir].Tanggal = Tanggal;
    qu.akhir++;
  }
  else
  {
    cout<<"Antrian Penuh! \n";
  }
  getchar();
}

void del()
{
  int i;
  if(!empty())
  {
    cout<<"Buku sudah dihapus"<<endl;
    for(i=qu.awal; i<qu.akhir; i++)
    {
      qu.Book[i]=qu.Book[i+1];
    }
    qu.akhir--;
  }
  else
  {
    cout<<"Buku Kosong"<<endl;
  }
  getchar();
}

//searching
void cari(int ID){
    if (!empty())
	{
		border();
		cout<<setiosflags(ios::left)<<setw(5)<<"ID"; cout<<" | ";
		cout<<setiosflags(ios::left)<<setw(20)<<"Judul Buku"; cout<<" | ";
		cout<<setiosflags(ios::left)<<setw(20)<<"Penulis Buku"; cout<<" | ";
		cout<<setiosflags(ios::left)<<setw(20)<<"Penerbit Buku"; cout<<" | ";
		cout<<setiosflags(ios::left)<<setw(20)<<"Tanggal Terbit"; cout<<" | " << endl;
		linemid();

        int awal = 0, akhir = qu.akhir+1, tengah;

        while(awal <= akhir){
            tengah = (awal + akhir)/2;
            if(ID > qu.Book[tengah].ID){
                awal = tengah + 1;
            }else if(ID < qu.Book[tengah].ID){
                akhir = tengah - 1;
            }else{
                awal = akhir + 1;
            }
        }

        if(ID == qu.Book[tengah].ID){
            cout<<setiosflags(ios::left)<<setw(5)<<qu.Book[tengah].ID; cout<<" | ";
            cout<<setiosflags(ios::left)<<setw(20)<<qu.Book[tengah].Judul; cout<<" | ";
            cout<<setiosflags(ios::left)<<setw(20)<<qu.Book[tengah].Penulis; cout<<" | ";
            cout<<setiosflags(ios::left)<<setw(20)<<qu.Book[tengah].Penerbit; cout<<" | ";
            cout<<setiosflags(ios::left)<<setw(20)<<qu.Book[tengah].Tanggal; cout<<" | "<<endl;
            border();
        }else{
            cout<<"Data tidak ditemukan";
        }
	}else
		cout<<"qu kosong"<<endl<<endl;
	 	
}

//selection sorting
//proses pengurutan secara ascending
void sorting(){
    int jmax;
    int u = qu.akhir-1;

    //proses pengurutan secara ascending
	for(int j = 0; j < qu.akhir; j++)
	{
		jmax = 0;
		for (int k = 1; k <= u; k++)
		{
			if (qu.Book[k].ID > qu.Book[jmax].ID)
			{
				jmax = k;
			}
		}

		qu.temp[j].ID = qu.Book[u].ID;
    	qu.Book[u].ID = qu.Book[jmax].ID;
    	qu.Book[jmax].ID = qu.temp[j].ID;

		qu.temp[j].Judul = qu.Book[u].Judul;
    	qu.Book[u].Judul = qu.Book[jmax].Judul;
    	qu.Book[jmax].Judul = qu.temp[j].Judul;

		qu.temp[j].Penulis = qu.Book[u].Penulis;
    	qu.Book[u].Penulis = qu.Book[jmax].Penulis;
    	qu.Book[jmax].Penulis = qu.temp[j].Penulis;

		qu.temp[j].Penerbit = qu.Book[u].Penerbit;
    	qu.Book[u].Penerbit = qu.Book[jmax].Penerbit;
    	qu.Book[jmax].Penerbit = qu.temp[j].Penerbit;

		qu.temp[j].Tanggal = qu.Book[u].Tanggal;
		qu.Book[u].Tanggal = qu.Book[jmax].Tanggal;
		qu.Book[jmax].Tanggal = qu.temp[j].Tanggal;


		u--;
	}
}

void tampil()
{
  if(!empty())
  {
    int i;
    sorting();
   cout << endl<< endl; border();
    cout<<setiosflags(ios::left)<<setw(5)<<"ID"; cout<<" | ";
    cout<<setiosflags(ios::left)<<setw(20)<<"Judul Buku"; cout<<" | ";
    cout<<setiosflags(ios::left)<<setw(20)<<"Penulis Buku"; cout<<" | ";
    cout<<setiosflags(ios::left)<<setw(20)<<"Penerbit Buku"; cout<<" | ";
    cout<<setiosflags(ios::left)<<setw(20)<<"Tanggal Terbit"; cout<<" | " << endl;
    for(i = qu.awal; i<qu.akhir; i++)
    {
      linemid();
      	cout<<setiosflags(ios::left)<<setw(5)<<qu.Book[i].ID; cout<<" | ";
		cout<<setiosflags(ios::left)<<setw(20)<<qu.Book[i].Judul; cout<<" | ";
		cout<<setiosflags(ios::left)<<setw(20)<<qu.Book[i].Penulis; cout<<" | ";
		cout<<setiosflags(ios::left)<<setw(20)<<qu.Book[i].Penerbit; cout<<" | ";
		cout<<setiosflags(ios::left)<<setw(20)<<qu.Book[i].Tanggal; cout<<" | " << endl;
    }
 	border();
    cout<<endl;
  }
  else
  {
    cout<<"Buku Kosong"<<endl<<endl;
  }
}


int main()
{
  int pilihan, ID,i;
  string Judul, Penulis, Tanggal, Penerbit;
  init();
  do
  {
    system("cls");
    linemid();
    cout<<"\t\t\t\t\t   MENU INPUT BUKU"<<endl;
    linemid();
    tampil();
   cout<<"[1] Buku Baru \n[2] Hapus Daftar Buku \n[3] Cari \n[4] Keluar"<<endl;
    cout<<"\n================="<<endl;
    cout<<"Masukkan Pilihan : "; cin>>pilihan;

    switch(pilihan)
    {
      case 1:
          cout<<"\nID Buku \t\t: "; 
          cin >> ID; 
          fflush(stdin);
          cout<<"Judul Buku \t\t: "; 
          getline(cin, Judul); 
          fflush(stdin);
          cout<<"Penulis Buku \t\t: "; 
          getline(cin, Penulis); 
          fflush(stdin);
          cout<<"Penerbit Buku \t\t: "; 
          getline(cin, Penerbit); 
          fflush(stdin);
          cout<<"Tanggal Masuk \t\t: "; 
          getline(cin, Tanggal); 
          fflush(stdin);
          add(ID, Judul, Penulis, Penerbit, Tanggal);
          break;
      case 2:
          del();
          break;
      case 3:
          cout<<"\nMasukan ID = "; cin>>ID;
          cout<<endl;
          cari(ID);
          cout<<"\nTekan ENTER untuk kembali ke Menu"<<endl;
          getch();
          break;
      case 4:
          cout<<"Terima Kasih"<<endl;
          break;
    }
  }
  while(pilihan!=4);
}
