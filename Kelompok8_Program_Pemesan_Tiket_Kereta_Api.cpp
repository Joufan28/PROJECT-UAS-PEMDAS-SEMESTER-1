#include <iostream>
#include <string>

using namespace std; 

const int max_length = 100;

struct Data_Penumpang_Kereta
{
    char nama[max_length];
    char jkelamin;
    int tgl[3];
};

struct TicketPrices {
    const int ekonomi = 50000;
    const int eks = 300000;
    const int bisnis = 200000;
};

void header(){
	for(int i=0; i<1; i++){
			cout << "**************************************"    << endl;
			cout << "           SELAMAT DATANG DI          "    << endl;
			cout << "   LOKET TIKET STASIUN SURABAYA GUBENG   " << endl;
			cout << "      JL. Stasiun Gubeng, Surabaya   "     << endl;
			cout << "***************************************"   << endl;
			cout 												<< endl;
	}
}

void selectTicketClass(int choice, int& harga, int& hrkelas, string& kode, const TicketPrices& prices) {
    switch (choice) {
        case 1:
            harga += prices.ekonomi;
            hrkelas = prices.ekonomi;
            kode += "E";
            break;
        case 2:
            harga += prices.bisnis;
            hrkelas = prices.bisnis;
            kode += "B";
            break;
        case 3:
            harga += prices.eks;
            hrkelas = prices.eks;
            kode += "S";
            break;
        default:
            system("cls");
            cout << "------------------------------------------------------------------------" << endl;
            cout << "| Opsi tidak tersedia. Mohon memilih opsi yang tertera pada tampilan!! |" << endl;
            cout << "------------------------------------------------------------------------" << endl;
    }
}


int main(){
	int tujuan, harga, kelas, hrtujuan, hrkelas, pjam;
	char lagi, pks, discard;
	string rute, jkelamin, jam, kode, ks;
    Data_Penumpang_Kereta orang;
    TicketPrices prices;
    
    char *namaLengkap = orang.nama;
    char OptionJK = tolower(orang.jkelamin);
    char OptionLG = tolower(lagi);
    char OptionKS = tolower(pks);
    
	
	do{
		header();
		
		cout << "Silahkan masukkan data anda : " << endl;
        cout << "   Nama               = "; 
        cin.getline(namaLengkap, max_length);
        do {
        cout << "   Jenis Kelamin[L/P] = ";
        cin >> orang.jkelamin;
        OptionJK = tolower(orang.jkelamin);

        switch(OptionJK) {
            case 'l' :
                jkelamin = "Laki - Laki";
                break;
            case 'p' :
                jkelamin = "Perempuan";
                break;
            default:
                system("cls");
                cout << "------------------------------------------------------------------------"  << endl;
                cout << "|            Harap masukkan jenis kelamin dengan huruf L/P             |"    << endl;
                cout << "------------------------------------------------------------------------"  << endl;
        }

        } while (OptionJK != 'l' && OptionJK != 'p');

	    do {
        cout << "   Masukkan Tanggal Keberangkatan [dd/mm/yy] = ";
        cin >> orang.tgl[0] >> discard >> orang.tgl[1] >> discard >> orang.tgl[2];
        cout << endl;

        if (cin.fail() || discard != '/' || orang.tgl[1] < 1 || orang.tgl[1] > 12 || orang.tgl[0] < 1 || orang.tgl[0] > 31) {
            system("cls");
            cout << "------------------------------------------------------------------------"  << endl;
            cout << "| Format tanggal tidak valid, Harap masukkan dengan format dd/mm/yy!!! |"  << endl;
            cout << "------------------------------------------------------------------------"  << endl;
        }

        } while (cin.fail() || discard != '/' || orang.tgl[1] < 1 || orang.tgl[1] > 12 || orang.tgl[0] < 1 || orang.tgl[0] > 31);
        
        system("cls");

		do {
        cout << "Silahkan pilih tujuan anda : "                   << endl;
        cout << "   ----------------------------------------------" << endl;
        cout << "   |No. |  Tujuan        |     Harga     |"          << endl;
        cout << "   ----------------------------------------------" << endl;
        cout << "   |1.  | Lamongan       | Rp. 300.000,- |"           << endl;
        cout << "   |2.  | Madiun         | Rp. 450.000,- |"           << endl;
        cout << "   |3.  | Malang         | Rp. 250.000,- |"           << endl;
        cout << "   |4.  | Jakarta        | Rp. 600.000,- |"           << endl;
        cout << "   ----------------------------------------------" << endl;

        cout << "Masukkan pilihan anda [1/2/3/4] = "; cin >> tujuan;

        switch(tujuan) {
            case 1 :
                harga = 300000;
                hrtujuan = 300000;
                rute = "Surabaya - Lamongan";
                kode ="SL";
                break;
            case 2 :
                harga= 450000;
                hrtujuan = 450000;
                rute = "Surabaya - Madiun";
                kode = "SM";
                break;  
            case 3 :
                harga = 250000;
                hrtujuan = 250000;
                rute = "Surabaya - Malang";
                kode = "SG";
                break;  
            case 4 :
                harga = 600000;
                hrtujuan = 600000;
                rute = "Surabaya - Jakarta";
                kode = "SJ";
                break;
            default :
                system("cls");
                cout << "--------------------------------------------------------------------------"  << endl;
                cout << "| Jadwal tidak tersedia. Mohon memilih opsi yang tertera pada tampilan!! |" << endl;
                cout << "--------------------------------------------------------------------------"  << endl;
                cout << ""  << endl;
        }

        } while (tujuan < 1 || tujuan > 4);
        
        system("cls");
		
		do {
		cout << "Silahkan pilih kelas :" 				    << endl;
		cout << "   --------------------------------------" << endl;
		cout << "   |N0. |  Kelas	|    Harga      |"      << endl;
		cout << "   --------------------------------------" << endl;
		cout << "   |1.  | Ekonomi	| Rp. 50.000,-  |"      << endl;
		cout << "   |2.  | Bisnis	| Rp. 200.000,- |"      << endl;
		cout << "   |3.  | Eksekutif	| Rp. 300.000,- |"  << endl;
		cout << "   --------------------------------------" << endl;
        cout << "Masukkan pilihan anda [1/2/3] = "; 
        cin >> kelas;

        selectTicketClass(kelas, harga, hrkelas, kode, prices);

        } while (kelas < 1 || kelas > 3);

		system("cls");
		do {
		cout << "Silahkan pilih jam keberangkatan : " << endl;
		cout << "   ---------------------------" 	  << endl;
		cout << "   |No. | Waktu  |    Jam    | "     << endl;
		cout << "   ---------------------------"	  << endl;
		cout << "   |1.  | Pagi   | 07.15 WIB | " 	  << endl;
		cout << "   |2.  | Siang  | 12.30 WIB | " 	  << endl;
		cout << "   |3.  | Malam  | 20.00 WIB | " 	  << endl;
		cout << "   ---------------------------" 	  << endl;
        cout << "Masukkan pilihan anda [1/2/3] = "; 
        cin >> pjam;

        switch(pjam) {
            case 1 :
                jam = "07.15 WIB";
                kode += "715P";
                break;    
            case 2 :
                jam = "12.30 WIB";
                kode += "123S";
                break;    
            case 3 :
                jam = "20.00 WIB";
                kode += "200M";
                break;
            default :
                system("cls");
                cout << "--------------------------------------------------------------------------"  << endl;
                cout << "| Jadwal tidak tersedia. Mohon memilih opsi yang tertera pada tampilan!! |" << endl;
                cout << "--------------------------------------------------------------------------"  << endl;
        }

        } while (pjam < 1 || pjam > 3);

		system("cls");
		
		cout << "   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "               TIKET KERETA API GAJAYANA           " << endl;
		cout << "   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "                                                   " << endl;
		
		cout << "       Kode tiket            = "		  << kode     << endl;
		cout << "       Nama Penumpang        = "		  << namaLengkap  << endl;
		cout << "       Jenis Kelamin         = "		  << jkelamin << endl;
		cout << "       Tujuan                = "		  << rute     << endl;
		cout << "       Tanggal Keberangkatan = ";
        	for (int i = 0; i < 3; ++i) {
    			if (orang.tgl[i] < 10) cout << '0';
            	cout << orang.tgl[i];
            	if (i < 2) cout << '/';
        	} 
		cout 														 << endl;
		cout << "       Jam keberangkatan     = "         << jam     << endl;
		cout << "                                                   "<< endl;
		cout << "       Keterangan harga                            "<< endl;
		cout << "          Harga tujuan       = Rp. "    << hrtujuan << endl;
		cout << "          Harga kelas        = Rp. "    << hrkelas  << endl;
		cout << "                                   ------- +"       << endl;
		cout << "          Total Harga        = Rp. "    << harga    << endl;
		
		cout << "                                                   " << endl;
		cout << "   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "             Jl. Stasiun Gubeng, Surabaya        "   << endl;
		cout << "   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout 														  << endl;
		

        do {
        cout << "Ingin memesan tiket lagi(y/t): "; 
        cin >> lagi;
        OptionLG = tolower(lagi);

        switch(OptionLG) {
            case 'y' :
                break;
            case 't' :
                break;
            default :
                system("cls");
                cout << "---------------------------------------------------------------------"  << endl;
                cout << "|          Mohon memilih opsi yang tertera pada tampilan!!          |"  << endl;
                cout << "---------------------------------------------------------------------"  << endl;
                
        }
        } while (OptionLG != 'y' && OptionLG != 't');
		system("cls");
        cin.ignore();
        
		
	} while(OptionLG == 'y');
    cout << "-----------------------------------------------------------------------------" << endl;
	cout << "		    Terima kasih telah memesan tiket.                           "       << endl;
    
    do{
    cout << "Apakah anda ingin memberikan kritik dan saran terhadap pelayanan kami?" 		<< endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "[y/t]: "; cin >> pks;
    system("cls");
    OptionKS = tolower(pks);
    switch(OptionKS) {
        case 'y':
			cout << "Silakan berikan kritik dan saran: ";
			cin.ignore();
			getline(cin, ks);
            system("cls");
			cout << "--------------------------------------------------" << endl;
			cout << "|       Terima kasih atas masukan Anda.          |" << endl;
			cout << "--------------------------------------------------" << endl;
			break;
		case 't':
			cout << "--------------------------------------------------" << endl;
			cout << "|   Terima kasih telah menggunakan layanan kami. |" << endl;
			cout << "--------------------------------------------------" << endl;
			break;
        default : 
            system("cls");
            cout << "---------------------------------------------------------------------"  << endl;
            cout << "|           Mohon memilih opsi yang tertera pada tampilan!!         |" << endl;
            cout << "---------------------------------------------------------------------"  << endl;
    }
    }while(OptionKS != 'y' && OptionKS != 't' );
	
return 0;
}