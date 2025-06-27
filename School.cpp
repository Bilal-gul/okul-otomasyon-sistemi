#include <iostream>
#include <cstring>

using namespace std;


class student{
	public:
	int examScore[3];
	string lessonsName[3]={"Matematik: ","Fizik: ","Programlama: "};
    void studentRegistration();
	void findStudent();
	string studentName[100];
    string studentSurname[100];
    void average();
	int examResult[100][3];
	int studentCounter=0;
    void show();
  
    
};



void student::studentRegistration(){
	string name;
	string surName;
	int counter;
	
	cout << "Kaç öğrenci girişi yapmak istersiniz: ";
	cin >> counter;
	
	for(int a = 0 ; a<counter ; a++){
			
	int b = a;		
	cout << b+1 <<". Öğrenci'nin ismini giriniz: ";
	cin >> name;
	
	cout << b+1 <<". Öğrenci'nin soyismini giriniz: ";
	cin >> surName;
	

	studentName[studentCounter]=name;
	studentSurname[studentCounter]=surName;
	
    studentCounter++;
}

	

}

void student::findStudent(){
	string name;
	string surName;
	cout << "Not girmek istediğiniz öğrencinin ismini giriniz: ";
	cin >> name;
	
	cout << "Not girmek istediğiniz öğrencinin soyismini giriniz: ";
	cin >> surName;
	
	
	
	bool isFind = false;
	
	for(int i = 0;i<100;i++){
		if(studentName[i] == name && studentSurname[i]==surName){
			
			isFind = true;
			
			cout << "Matematik notu: ";
			cin >> examScore[0];
			
			cout << "Fizik notu: ";
			cin >> examScore[1];
			
			cout << "Programlama notu: ";
			cin >> examScore[2];
			
			examResult[i][0]=examScore[0];
		    examResult[i][1]=examScore[1];
		    examResult[i][2]=examScore[2];
		
			
			
			break;
		}
	
	}
	
	if(isFind==false)
	cout << "Aradığınız isim ve soy isimde öğrenci bulunamadı!!!";
		
	
}

void student::average(){
	
	int examAverage;
	string name;
	string surName;

cout << "Ortalamasını görmek istediğiniz öğrencinin ismini giriniz: ";
cin >> name;

cout << "Ortalamasını görmek istediğiniz öğrencinin soyismini giriniz: ";
cin >> surName;

bool is=false;

for(int j = 0;j<100;j++){
	if(studentName[j] == name && studentSurname[j] == surName){
	
	    is=true;
	
		examAverage = examResult[j][0]+examResult[j][1]+examResult[j][2];
		
		cout << "Not ortalaması: "<<examAverage/3 << endl;	
		
		break;
	 }
	

}

		if(is==false)
		cout << "Yanlış bir isim girdiniz!!!"<< endl;
}


void student::show(){
	
	int examAverage;
	string name;
	string surName;
	
 cout << "Bilgilerini görmek istediğiniz öğrencinin ismini giriniz: ";
 cin >> name;

 cout << "Bilgilerini görmek istediğiniz öğrencinin soyismini giriniz: ";
 cin >> surName;

 bool found=false;

 for(int e = 0;e<100;e++){
	if(studentName[e] == name && studentSurname[e] == surName){
	
	    found=true;
	
	cout << "Öğrencinin ismi: " << name << endl;
	cout << "Öğrencinin soyismi: " << surName << endl;
	cout << "------------------" <<endl;
	cout << "Notlar : " << endl;
	cout << lessonsName[0] << examResult[e][0] << endl;
	cout << lessonsName[1] << examResult[e][1] << endl;
	cout << lessonsName[2] << examResult[e][2] << endl;	
	examAverage = examResult[e][0]+examResult[e][1]+examResult[e][2];
		
	cout << "Not ortalaması: "<<examAverage/3 << endl;
	
		break;
	}

}
	if(found==false)
		cout << "Yanlış bir isim girdiniz!!!"<< endl;

}




void information(){
	cout << endl;
	cout << endl;
	cout << "----------------------------" << endl;
	cout << "1 - Öğrenci kayıtları" << endl;
	cout << "2 - Not girişleri" << endl;
	cout << "3 - Not ortalaması hesaplama" << endl;
	cout << "4 - Öğrenci bilgisi görüntüleme" << endl;
	cout << "5 - Çıkış" << endl;
	cout << "----------------------------" << endl;
}

int main() {
	
	int selection = 0;
	student registration;

	do{
		
	information();
	
	cout << "Yapmak istediğiniz işlemi seçiniz: ";
	cin >> selection;
	
	
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Geçersiz giriş! Lütfen sadece sayı giriniz." << endl;
            continue; 
        }
	
	switch(selection){
		
		case 1:
			registration.studentRegistration();
		break;
		
		case 2:
		   	registration.findStudent();
		break;
		
	    case 3:
	    	registration.average();
		break;
		
		case 4:
			registration.show();
		break;
		
		case 5:
		    break;
		
		default:
		cout << "Yanlış bir seçim yaptınız..Tekrar deneyiniz." << endl;
	    break;
	}
	
	      }while(selection!=5);
	
	
	return 0;
}