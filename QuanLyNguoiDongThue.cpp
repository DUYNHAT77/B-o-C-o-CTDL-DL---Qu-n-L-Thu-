#include<bits/stdc++.h>
using namespace std;

//===Quan Ly Nguoi Dong Thue(Danh sach lien ket don)===

struct NGUOIDONGTHUE
{
	int maNguoiDT;
	int maThue;
	char tenCongTy[100];
	char diaChi[100];
	float dienTich;
	char quyMo[20];
	char nguoiDungDau[50];
	float donGia;
	float tienThue;
	
};

//ds lk don

struct Node
{
	NGUOIDONGTHUE info;
	struct Node*next;
};

struct List
{
	Node *Head;
	Node *Tail;
};
//khoi tao ds rong
void KhoiTao(List &Q)
{
	Q.Tail=NULL;
	Q.Head=NULL;
}
//tao nut chua thong tin can bo
Node *getNode(NGUOIDONGTHUE x)
{
	Node *pNDT;
	pNDT=new Node;
	if(pNDT==NULL)
	{
		cout<<"cap phat loi"<<endl;
		return 0;
	}
	pNDT->info=x;
	pNDT->next=NULL;
	return pNDT;
}
void insertLast(List &Q, Node *pNDT)
{
	if(Q.Head==NULL)
	{
		Q.Head=pNDT;
		Q.Tail=Q.Head;
	}
	else 
	{
		Q.Tail->next=pNDT;
		Q.Tail=pNDT;
	}
}
void nhapNDT(NGUOIDONGTHUE &x)
{
	cout<<"nhap ma nguoi dong thue:"; cin>>x.maNguoiDT;
	cout<<"nhap ma thue: "; cin>>x.maThue;
	fflush(stdin);
	cout<<"Nhap ten cong ty: "; gets(x.tenCongTy);
	cout<<"Nhap dia chi: "; gets(x.diaChi);
	cout<<"Nhap quy mo: "; gets(x.quyMo);
	cout<<"Nhap nguoi dung dau: "; gets(x.nguoiDungDau);
	cout<<"Nhap dien tich: "; cin>>x.dienTich;
	if(x.dienTich<3000){
		x.donGia=5000;
		x.tienThue=5000*x.dienTich;
	}else if(x.dienTich>=3000 and x.dienTich<=5000){
		x.donGia=4000;
		x.tienThue=4000*x.dienTich;
	}else if (x.dienTich>5000){
		x.donGia=3000;
		x.tienThue=3000*x.dienTich;
	}
	
}
void NhapDSNDT(List &Q)
{
	int n;
	Node *pNDT;
	NGUOIDONGTHUE x;
	cout<<"nhap so nguoi dong thue: "; cin>>n;
	for (int i=0;i<n;i++)
	{
		nhapNDT(x);
		pNDT=getNode(x);
		insertLast(Q,pNDT);
	}
	
}

void xuatNDT(NGUOIDONGTHUE x)
{
	cout<<setw(18)<<left<<x.maNguoiDT<<"\t";
	cout<<setw(8)<<left<<x.maThue<<"\t";
	cout<<setw(12)<<left<<x.tenCongTy<<"\t";
	cout<<setw(7)<<left<<x.quyMo<<"\t";
	cout<<setw(10)<<left<<x.diaChi<<"\t";
	cout<<setw(18)<<left<<x.nguoiDungDau<<"\t";
	cout<<setw(8)<<left<<x.dienTich;
	cout<<endl;
	cout<<setw(7)<<left<<x.donGia;
	cout<<setw(10)<<left<<x.tienThue;
	cout<<endl;
	
}
void xuatDSNDT(List &Q)
{
	Node*pNDT;
	cout<<"danh sach hien co:"<<endl;
	cout<<setw(18)<<left<<"Ma Nguoi Dong Thue"<<"\t"
	<<setw(8)<<left<<"Ma Thue"<<"\t"
	<<setw(12)<<left<<"Ten Cong Ty"<<"\t"
	<<setw(7)<<left<<"Quy Mo"<<"\t"
	<<setw(10)<<left<<"Dia Chi"<<"\t"
	<<setw(18)<<left<<"Nguoi Dung Dau"<<"\t"
	<<setw(8)<<left<<"Dien Tich"<<"\t";
	cout<<endl;
	cout<<setw(7)<<left<<"Don Gia"<<"\t"
	<<setw(10)<<left<<"Thanh Tien";
	cout<<endl;
	for(pNDT=Q.Head;pNDT!=NULL;pNDT=pNDT->next)
	   xuatNDT(pNDT->info);
}


//tim lkien
Node *search(List &Q, int k)
{
	Node *pNDT;
	for (pNDT=Q.Head;pNDT!=NULL;pNDT=pNDT->next)
	    if (pNDT->info.maNguoiDT==k) break;
	    return pNDT;
}
void sapxeptheodientich(List &Q)
{
	Node *pNDT, *q;
	NGUOIDONGTHUE tg;
	for(pNDT=Q.Head;pNDT!=NULL;pNDT=pNDT->next)
	   for (q=pNDT->next;q!=NULL;q=q->next)
	     if (pNDT->info.dienTich > q->info.dienTich)
	       {
	       	tg=pNDT->info;
	      	pNDT->info=q->info;
	      	q->info=tg;
		   }   
}

void ThongKe(List &Q, char quyMo[]){
	Node *pNDT;
	for(pNDT=Q.Head;pNDT!=NULL;pNDT=pNDT->next)
		if (strcmp(pNDT->info.quyMo,quyMo)==0){
			xuatNDT(pNDT->info);
		}
}

void Sapxepdiachi(List &Q){
	Node *pNDT, *q;
	NGUOIDONGTHUE tg;
	for(pNDT=Q.Head;pNDT!=NULL;pNDT=pNDT->next)
	   for (q=pNDT->next;q!=NULL;q=q->next)
	     if (strcmp(pNDT->info.diaChi, q->info.diaChi)>0)
	       {
	       	tg=pNDT->info;
	      	pNDT->info=q->info;
	      	q->info=tg;
		   } 
		  xuatDSNDT(Q);  
}
//xoa theo ma dong thue

void Remove(List &Q, int ma)
{
	Node *pNDT=Q.Head, *q=NULL;
	while(pNDT!=NULL){
		if(pNDT->info.maNguoiDT==ma) break;
		q=pNDT;
		pNDT=pNDT->next;	
	}
	if(pNDT==NULL) cout<<"Khong tim thay ma"<<endl;
	if(q!=NULL)
	{
		if(q==Q.Tail) 
		Q.Tail=q;
		q->next=pNDT->next;
		delete pNDT;
	}
	else
	{
		Q.Head=pNDT->next;
		if(Q.Head==NULL) Q.Head=NULL;
	}
	cout<<"Xoa thanh cong"<<endl;
}

//cho biet Cong ty co dia chi tai x

void TimDiaChi(List &Q, char x[])
{
	Node*pNDT;
	cout<<"Danh sach cong ty co dia chi "<<x<<" la:"<<endl;
	for(pNDT=Q.Head;pNDT!=NULL;pNDT=pNDT->next)
	if (strcmp(pNDT->info.diaChi,x)==0)
	xuatNDT(pNDT->info);
	cout<<endl;
}

void DienTichMax(List &Q){
	Node *pNDT;
	float max=-1;
	for(pNDT=Q.Head;pNDT!=NULL;pNDT=pNDT->next)
		if(max < pNDT->info.dienTich)
		 max=pNDT->info.dienTich;
	for(pNDT=Q.Head;pNDT!=NULL;pNDT=pNDT->next)
	if(pNDT->info.dienTich==max)
	xuatNDT(pNDT->info);
}

void Sua(List &Q) {
	Node *pNDT,*qNDT,*m;
	NGUOIDONGTHUE x;
	int maNDT;
	cout<<"Nhap ma nguoi dong thue can sua: "; cin>>maNDT;
	for(pNDT=Q.Head;pNDT!=NULL;pNDT=pNDT->next)
		if(pNDT->info.maNguoiDT==maNDT){
			qNDT=pNDT;
		}
	for(pNDT=Q.Head;pNDT!=NULL;pNDT=pNDT->next)
		if(pNDT->next==qNDT){
			m=pNDT;
		}
	        nhapNDT(x);
			Node *q=getNode(x);
			if(m->next==NULL){
				Q.Tail->next=q;
				Q.Tail=q;
			}else{
			Node *h= getNode(q->info);
			Node *tg =m->next;
			h->next=tg;
			m->next=h;
			}
	Remove(Q,maNDT);
	xuatDSNDT(Q);
		
}



void chenphantusauma(List &Q){
	Node *p, *q;
	int maChen,dem=0;
	NGUOIDONGTHUE x;
	cout<<"Nhap ma can chen: "; cin>>maChen;
	for(p=Q.Head;p!=NULL;p=p->next)
			if(p->info.maNguoiDT==maChen){
			dem++;
			nhapNDT(x);
			q=getNode(x);
			if(p->next==NULL){
				Q.Tail->next=q;
				Q.Tail=q;
			}else{
				Node *h=getNode(q->info);
				Node *k=p->next;
				h->next=k;
				p->next=h;
			}
		}
	if(dem==0) cout<<"Khong tim thay ma"<<endl;
	xuatDSNDT(Q);
	
}
//Luu file
void Luufile(FILE *f, List &Q, char *name)
{
	f=fopen(name,"w+b");
	int n=0;
	Node *pNDT;
	for(pNDT=Q.Head;pNDT!=NULL;pNDT=pNDT->next)
	{
	n=n+1;
	}
	fwrite(&n,sizeof(int),1,f);
	for(pNDT=Q.Head;pNDT!=NULL;pNDT=pNDT->next){
	fwrite(&pNDT->info,sizeof(NGUOIDONGTHUE),1,f);
	}
	fclose(f);
	cout<<"Ghi file thanh cong"<<endl;
}


void DocFile(FILE *f, List &Q, char *name)
{
	NGUOIDONGTHUE x;
	int i,n;
	Node *pNDT;
	KhoiTao(Q);
	f=fopen(name,"r+b");
	if(f==NULL)
	{
		cout<<"Mo tep khong thanh cong"<<endl;
		return;
	}
	cout<<"Bat dau doc file"<<endl;
	fread(&n,sizeof(int),1,f);
	for(i=0;i<n;i++)
	{
		fread(&x,sizeof(NGUOIDONGTHUE),1,f);
		pNDT=getNode(x);
		insertLast(Q,pNDT);
	}
	fclose(f);
	cout<<"doc file thanh cong"<<endl;
	xuatDSNDT(Q);
}

//===Quan Ly Phieu Thu Thue(Danh sach lien ket doi)===

// using namespace std;
struct phieuthu {
	int mapt;
	string thoigian, nguoilap, hotennguoinop;
	float tongtien, sotiengiam, sotiencandong;
	
};


struct NodePT{
	phieuthu info;
	struct NodePT*next; 
	struct NodePT*prev;
};


struct LISTPT{
	NodePT*Head;
	NodePT*Tail;
};


LISTPT PT;
void khoitaoPT ( LISTPT & PT )
{
	PT.Head = NULL;
	PT.Tail = NULL;
}

NodePT * GetNode( phieuthu x  )
{
	NodePT *p;
	p = new NodePT();
	if (p == NULL)
{
	cout<<("Ko du bo nho");
	exit(1);
}
	p -> info = x;
	p -> next = NULL;
	p -> prev = NULL;
	return p;
} 


void chencuoipt( LISTPT & PT, NodePT *p )
{
if ( PT.Head == NULL ) //nêu danh sách rông
{
PT.Head = p;
PT.Tail = PT.Head;
}
else //danh sách không rông
{
PT.Tail->next=p;
p->prev=PT.Tail;
PT.Tail=p;
}
}
void nhappt ( phieuthu &x){
	cout<<"\nma phieu thu: ";
	cin>>x.mapt;
	cout<<"\nho ten nguoi nop: ";
	cin.ignore();
	getline(cin,x.hotennguoinop);
	cout<<"\nthoi gian lap: ";
	getline(cin, x.thoigian);
	cout<<"\nnhap tong tien: ";
	cin>>x.tongtien;
	cout<<"\ntien giam tru: ";
	cin>>x.sotiengiam;
	x.sotiencandong= x.tongtien - x.sotiengiam;
	
}

void nhapdspt ( LISTPT & PT){
	int n;
	NodePT * p;
	phieuthu x;
	cout <<" nhap so phieu thu: "; cin>>n;
	for (int i=1 ; i<=n ; i++)
	{
		nhappt (x);
		p = GetNode(x); 
		chencuoipt( PT, p);
		}
		
}


void xuatpt ( phieuthu x){
	cout<<"\n"<<setw(5) << x.mapt;
	cout<<setw(15)<< x.hotennguoinop;
	cout<<setw(15)<< x.thoigian;
	cout<<setw(15)<< x.tongtien;
	cout<<setw(17)<< x.sotiengiam;
	cout<<setw(17)<< x.sotiencandong;
}


void xuatdspt ( LISTPT & PT){
	NodePT *p;
	cout<<"\n ds phieu thu hien co: \n";
	cout<<"\n"<<setw(8) << "ma pt";
	cout<<setw(20)<< "ho ten nguoi dong";
	cout<<setw(15)<< "thoi gian";
	cout<<setw(15)<< "tong tien";
	cout<<setw(17)<< "so tien giam";
	cout<<setw(17)<< "so tien can dong";
	for ( NodePT *p = PT.Head; p!= NULL;p = p->next)
	xuatpt( p->info);	
}
NodePT * timmapt ( LISTPT &PT, int mpt ){
	NodePT *p;
	for (p=PT.Head; p!=NULL; p=p->next)
	if (p->info.mapt == mpt)
	break;
	return p;
}
void sapxeppt(LISTPT PT){
	NodePT *p;
	NodePT *q;
	phieuthu tg;
	cout<<"\nsap xep theo so tien can dong";
	for(p = PT.Head; p!=NULL; p=p->next)
	for(q=p->next ; q!=NULL ; q=q->next){
		if(p->info.sotiencandong<q->info.sotiencandong)
		{
			tg=p->info;
			p->info=q->info;
			q->info=tg;
		}
	}
	xuatdspt(PT);	
}
void luuf(LISTPT PT){
	FILE *f;
	char filename[20];
	cout<<"Nhap ten FILE: ";fflush(stdin);gets(filename);
	f=fopen(filename,"w+b");
	for (NodePT *p= PT.Head; p != NULL; p = p->next){
		fwrite(&p->info,sizeof(phieuthu),1,f);
}
			fclose(f);
	FILE *t;
	t=fopen("Ten FILE","a+b");
	fwrite(&filename,sizeof(filename),1,t);
	cout<<"Da luu vao: "<<filename<<endl;
	fclose(t);


}
void docf(LISTPT PT){
	khoitaoPT(PT);
	FILE *f;
	phieuthu x;
	char filename[20];
	NodePT*p;
	cout<<"Mo file:\nCac FILE da luu:"<<endl;
	char Ten[20];
	FILE *t;
	int i=0;
	t=fopen("Ten FILE","r+b");
while(true)
 {
 if(t == NULL){ fclose(t);
break; 
}
 	fread(&Ten ,sizeof(Ten),1,t);
 	if(feof(t))break;
 	i++;
 	cout<<"File "<<i<<": "<<Ten<<endl;
 	}
 	fclose(t);
	cout<<"Nhap ten FILE muon mo: ";fflush(stdin);gets(filename);
	f=fopen(filename,"r+b");
if(f == NULL)
 {
	 cout<<"\nLoi mo tep";
	 return;
 	}
 	while(true)
 	{
 	fread(&x ,sizeof(phieuthu),1,f);
 	if(feof(f))break;
 	p=GetNode(x);
 	chencuoipt(PT,p);
 	}

 while(!feof(f));
 
 	fclose(f);
 	cout<<"Danh sach trong file "<<filename<<" la:"<<endl;
 	xuatdspt(PT);
}


void XoaNodeDau(LISTPT &PT){
	{
		if (PT.Head != NULL)
		{
			NodePT *p = PT.Head; 
			PT.Head = PT.Head->next;
			PT.Head->prev=NULL;
			delete p;
		}
		if(PT.Head==NULL)
		{
			khoitaoPT(PT);
		}
	}
}

void XoaNodeCuoi(LISTPT &PT){
if (PT.Head->next == NULL)
{
XoaNodeDau(PT);
return;
}
for (NodePT *p = PT.Head; p != NULL; p = p->next)
{
if (p->next == PT.Tail)
{
delete PT.Tail;
p->next = NULL; 
PT.Tail = p; 
}
}
}

void XoaNodeCoKhoaBatKy (LISTPT &PT,int xoa ){
	 NodePT *p;
	p = timmapt (PT,xoa); //Tìm ki?m ph?n t? d? xóa
	if ( p == NULL ){
		cout<<"ko co phan tu"; exit(1);
	}
else
	{
if ( ( p == PT.Head ) && ( p == PT.Tail) )
			{ PT.Head = NULL; PT.Tail = NULL; }
else if ( p == PT.Head ) PT.Head = p->next;
else if ( p == PT.Tail ) PT.Tail = p -> prev; 
else
	{
		p -> prev -> next = p -> next;
		p -> next -> prev = p -> prev;
	}
	free(p);
	}
}



int main()
{
	List Q;
	Node *pNDT;
	int k,chon,luachon,choose;
	KhoiTao(Q);
	FILE *f;
	NodePT *p;
	khoitaoPT(PT);
	char filename[20] = "nguoidongthue.txt" ;
	do{
		cout<<"\t|1.Quan Ly Nguoi Dong Thue "<<endl;
		cout<<"\t|2.Quan Ly Phieu Thu "<<endl;
		cout<<"\t|0.Thoat "<<endl;
		cout<<"Xin moi chon: "; cin>>luachon;
		switch(luachon)
		{
			case 1: {
						do{
						cout<<"\t|1.Nhap danh sach nguoi dong thue "<<endl;
						cout<<"\t|2.In danh sach nguoi dong thue "<<endl;
						cout<<"\t|3.Tim kiem theo ma nguoi dong thue "<<endl;
						cout<<"\t|4.Sap xep theo dien tich "<<endl;
						cout<<"\t|5.Xoa theo nguoi dong thue theo ma "<<endl;
						cout<<"\t|6.Tim dia chi "<<endl;
						cout<<"\t|7.Luu File "<<endl;
						cout<<"\t|8.Doc File "<<endl;
						cout<<"\t|9.Tim dien tich lon nhat "<<endl;
						cout<<"\t|10.Sua nguoi dong thue "<<endl;
						cout<<"\t|11.Chen nguoi dong thue sau ma nao do "<<endl;
						cout<<"\t|12.Danh sach theo quy mo "<<endl;
						cout<<"\t|13.Sap xep dia chi "<<endl;
						cout<<"\t|0.Thoat "<<endl;
						cout<<"chon: "; cin>>chon;
						switch(chon)
						{
							case 1: NhapDSNDT(Q);
									Luufile(f,Q,filename); break;
							case 2: xuatDSNDT(Q); break;
							case 3:
							cout<<"nhap ma nguoi dong thue k: "; cin>>k;
							pNDT=search(Q,k);
							if (pNDT==NULL)
							{
								cout<<"Khong tim thay"<<endl;
							}else
							{
								cout<<"Tim thay"<<endl;
								xuatNDT(pNDT->info);
							 } 
						     break;
							case 4: sapxeptheodientich(Q); xuatDSNDT(Q); 
									Luufile(f,Q,filename); break;
							case 5: int ma;
									cout<<"Nhap ma nguoi dong thue can xoa: "; cin>>ma;
									Remove(Q,ma); xuatDSNDT(Q); 
									Luufile(f,Q,filename); break;
							case 6: char x[20];
									fflush(stdin);
									cout<<"nhap dia chi can tim x: "; gets(x);
									TimDiaChi(Q,x);
									break;
							case 7: Luufile(f,Q,filename); break;
							case 8: DocFile(f,Q,filename); break;
							case 9: DienTichMax(Q); break;
							case 10: Sua(Q);
								Luufile(f,Q,filename);
								 break;
							case 11: chenphantusauma(Q); 
								Luufile(f,Q,filename);
								break;
								
							case 12: 
							char quymo[12];
							fflush(stdin);
							cout<<"nhap quy mo: "; gets(quymo);
							ThongKe(Q,quymo);
							break;
							case 13: Sapxepdiachi(Q); break;
							case 0: exit(0);
						
						}
						
					}while(chon!=0);
				break;
			}
			case 2: {
						do{
						cout<<"\n 1,nhap dspt";
						cout<<"\n 2.in dspt";
						cout<<"\n 3.tim kiem ma pt: ";
						cout<<"\n 4.sxpt theo thanh tien giam dan:";
						cout<<"\n 5.xoa phieu thu theo ma: ";
						cout<<"\n 6 xoa phieu thu dau tien: ";
						cout<<"\n 7 xoa phieu thu cuoi cung: ";
						cout<<"\n 8.luu file: ";
						cout<<"\n 9.doc file: ";
						cout<<"\n 0 thoat";
						cout<<"\n chon:";
						cin>>choose;
						switch(choose)
						{
							case 1: nhapdspt(PT); break;
							case 2: xuatdspt(PT);break;
							case 3:
								{
								cout<<"\n nhap ma can tim";
								cin>>k;
								p= timmapt(PT, k);
								if ( p== NULL)
								cout<<"\n khong tim thay ";
								else {
									cout<<"\n pt can tim la";
									cout<<"\n"<<setw(10) << "ma pt";
									cout<<setw(10)<< "ho ten nguoi dong";
									cout<<setw(10)<< "thoi gian";
									cout<<setw(10)<< "tong tien";
									cout<<setw(10)<< "so tien giam";
									cout<<setw(10)<< "so tien can dong";
									xuatpt (p->info);
									
								}
								}break;
								case 4: 
								{
								cout<<"danh sach pt da sap xep:";
								sapxeppt(PT);
								cout<<"\n";
								}break;
								
								case 5: 
								int xoa;
								cout<<"nhap ma can xoa";
								cin>>xoa;
								XoaNodeCoKhoaBatKy(PT,xoa);
								cout<<"danh sach sau khi xoa:";
								xuatdspt(PT);
								break;
								
								case 6: {
								XoaNodeDau(PT);
								cout<<"ds sau khi xoa phan tu dau tien: \n";
								xuatdspt(PT);
								}
								break;
								
								case 7:{
									XoaNodeCuoi(PT);
									cout<<"danh sach sau khi xoa phan tu cuoi cung:\n";
									xuatdspt(PT);
									break;
								}
								
								case 8:{
									luuf( PT);
								return 0; }break;
							
								case 9: {
									docf( PT );return 0; }break;
							 	case 0 :
							 	exit(0);
							 
							
						}
					}
					while (choose!=0);
								break;
							}
			case 0: exit(0);
		}
	}while(luachon!=0);
}
