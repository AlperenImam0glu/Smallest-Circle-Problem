#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <math.h>
#define genislik 800
#define yukseklik 800

void grafik(float x[], float y[], int k, double gx, double gy, double cap, int uzakNokta) {

	int i;
	al_init_primitives_addon();
	 
	ALLEGRO_DISPLAY* display = NULL;

	al_init();


	display = al_create_display(genislik, yukseklik);

	//x-y eksenleri


	al_draw_line(0, yukseklik / 2, genislik, 400, al_map_rgb_f(254, 254, 254), 3);//x ekseni
	al_draw_line(genislik / 2, 0, genislik / 2, yukseklik, al_map_rgb_f(254, 254, 254), 3);//y ekseni

	for (int i = 0; i <= 40; i++) {

		if (i == 20) {
			continue;
		}

		//karelere ayrılış
		al_draw_line(0, i * 20, 800, i * 20, al_map_rgb(80, 80, 80), 1);
		al_draw_line(i * 20, 0, i * 20, 800, al_map_rgb(80, 80, 80), 1);
	}

	for (int i = 0; i <= 40; i++) {
		//nokta çentikleri
		al_draw_line(i * 20, 405, i * 20, 395, al_map_rgb_f(254, 254, 254), 3);
		al_draw_line(395, i * 20, 405, i * 20, al_map_rgb_f(254, 254, 254), 3);
	}

	for (i = 0; i < k; i++) {

		//noktaların yazdırılısı
		al_draw_filled_circle(x[i], y[i], 6, al_map_rgb(255, 0, 0));
	}

	cap = cap * 20;
	al_draw_filled_circle(gx, gy, 6, al_map_rgb(255, 255, 0));//merkez noktası
	al_draw_circle(gx, gy, cap, al_map_rgb_f(255, 255, 255), 1);//çember
	al_draw_line(gx, gy, x[uzakNokta], y[uzakNokta], al_map_rgb(255, 246, 143), 2);//yarıcap

	float v, m;
	int n0, n1, n2, n3; //kontrol noktaları

	float kare;
	float küp;

	float k1, k2, k3, k4;
	float Sx, Sy;
	int sayac = 0;

	for (m = 0; m < k - 1; m += 0.001) {

		v = m;
		//n1=0,n2=1;n3=2;n0=7       
		//-------kontrol noktaları---------
		n1 = (int)v;
		n2 = (n1 + 1) % k;
		n3 = (n2 + 1) % k;
		if (n1 >= 1) {
			n0 = n1 - 1;
		}
		else {
			n0 = k - 1;
		}

		//her adımda cizim n1 - n2 arasında olmalıdır.
		//---------------------------------

		//-------katsayılar----------------
		v = v - (int)v;
		//tam sayı kısmı atıldı
		kare = v * v;
		küp = kare * v;

		k1 = -küp + (2.0 * kare) - v; // her daim negatif deger
		k2 = (3.0 * küp) - (5.0 * kare) + 2.0;// her daim porzitif deger
		k3 = (-3.0 * küp) + (4.0 * kare) + v;// her daim pozitif deger
		k4 = küp - kare;// her daim negatif deger

		//---------------------------------

		Sx = 0.5f * (x[n0] * k1 + x[n1] * k2 + x[n2] * k3 + x[n3] * k4);
		Sy = 0.5f * (y[n0] * k1 + y[n1] * k2 + y[n2] * k3 + y[n3] * k4);

		//spline noktaları
		al_draw_filled_circle(Sx, Sy, 1, al_map_rgb(255, 187, 255));


		/*printf("%f ", t);
		printf("    %d %d %d %d\n", p0, p1,p2,p3);
		printf("%f,%f,%f,%f\n",q1,q2,q3,q4 );*/


	}

	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_FONT* font = al_load_font("Orbitron Black.ttf", 14, 0);

	al_draw_text(font, al_map_rgb(255, 255, 255), 430, 405, 0, " 2");
	al_draw_text(font, al_map_rgb(255, 255, 255), 470, 405, 0, " 4");
	al_draw_text(font, al_map_rgb(255, 255, 255), 510, 405, 0, " 6");
	al_draw_text(font, al_map_rgb(255, 255, 255), 550, 405, 0, " 8");
	al_draw_text(font, al_map_rgb(255, 255, 255), 590, 405, 0, "10");
	al_draw_text(font, al_map_rgb(255, 255, 255), 630, 405, 0, "12");
	al_draw_text(font, al_map_rgb(255, 255, 255), 670, 405, 0, "14");
	al_draw_text(font, al_map_rgb(255, 255, 255), 710, 405, 0, "16");
	al_draw_text(font, al_map_rgb(255, 255, 255), 750, 405, 0, "18");

	al_draw_text(font, al_map_rgb(255, 255, 255), 345, 405, 0, " -2");
	al_draw_text(font, al_map_rgb(255, 255, 255), 305, 405, 0, " -4");
	al_draw_text(font, al_map_rgb(255, 255, 255), 265, 405, 0, " -6");
	al_draw_text(font, al_map_rgb(255, 255, 255), 225, 405, 0, " -8");
	al_draw_text(font, al_map_rgb(255, 255, 255), 185, 405, 0, "-10");
	al_draw_text(font, al_map_rgb(255, 255, 255), 145, 405, 0, "-12");
	al_draw_text(font, al_map_rgb(255, 255, 255), 105, 405, 0, "-14");
	al_draw_text(font, al_map_rgb(255, 255, 255), 65, 405, 0, "-16");
	al_draw_text(font, al_map_rgb(255, 255, 255), 20, 405, 0, "-18");

	al_draw_text(font, al_map_rgb(255, 255, 255), 380, 350, 0, " 2");
	al_draw_text(font, al_map_rgb(255, 255, 255), 380, 310, 0, " 4");
	al_draw_text(font, al_map_rgb(255, 255, 255), 380, 270, 0, " 6");
	al_draw_text(font, al_map_rgb(255, 255, 255), 380, 230, 0, " 8");
	al_draw_text(font, al_map_rgb(255, 255, 255), 380, 190, 0, "10");
	al_draw_text(font, al_map_rgb(255, 255, 255), 380, 150, 0, "12");
	al_draw_text(font, al_map_rgb(255, 255, 255), 380, 110, 0, "14");
	al_draw_text(font, al_map_rgb(255, 255, 255), 380, 70, 0, "16");
	al_draw_text(font, al_map_rgb(255, 255, 255), 380, 30, 0, "18");

	al_draw_text(font, al_map_rgb(255, 255, 255), 375, 435, 0, "-2");
	al_draw_text(font, al_map_rgb(255, 255, 255), 375, 475, 0, "-4");
	al_draw_text(font, al_map_rgb(255, 255, 255), 375, 515, 0, "-6");
	al_draw_text(font, al_map_rgb(255, 255, 255), 375, 555, 0, "-8");
	al_draw_text(font, al_map_rgb(255, 255, 255), 375, 595, 0, "-10");
	al_draw_text(font, al_map_rgb(255, 255, 255), 375, 635, 0, "-12");
	al_draw_text(font, al_map_rgb(255, 255, 255), 375, 675, 0, "-14");
	al_draw_text(font, al_map_rgb(255, 255, 255), 375, 715, 0, "-16");
	al_draw_text(font, al_map_rgb(255, 255, 255), 375, 755, 0, "-18");

	al_flip_display();

	system("pause");
}

void Koordinat_Duzenleme(float x[], float y[], int k, float merkez[]) {

	int i = 0;
	while (i < k) {

		x[i] = x[i] * 20;
		y[i] = y[i] * 20;

		x[i] = genislik / 2 + x[i];
		y[i] = yukseklik / 2 - y[i];

		i = i + 1;
	}

	merkez[0] = merkez[0] * 20;
	merkez[1] = merkez[1] * 20;
	merkez[0] = genislik / 2 + merkez[0];
	merkez[1] = yukseklik / 2 - merkez[1];

}

void Hesap(float x[], float y[], int k, float veriler[]) {

	float uzaklık[100];

	double gx = 0, gy = 0, tx = 0, ty = 0;
	double  ara1 = 0, ara2 = 0, geciciXm, geciciYm;

	int i = 0, j = 0, uzakNokta1 = 0, uzakNokta2;
	int kontrolSayac = 1, kontrolSayac2 = 1;

	double enuzak = 0, enuzak2;
	double y_farki, x_farki, m_uzak2, sayac = 0, sayac2 = 0, islem = 0, ifislem = 0, enbuyuk_yaricap = 0;

	//gecici merkez ;
	for (i = 0; i < k; i++)
	{
		tx = tx + x[i];
		ty = ty + y[i];
	}

	gx = tx / k;
	gy = ty / k;


	//gecici merkeze en uzak noktayı bulan kod ;
	for (i = 0; i < k; i++)
	{
		ara1 = pow(gx - x[i], 2);
		ara2 = pow(gy - y[i], 2);
		enuzak2 = sqrt(ara1 + ara2);

		if (enuzak2 > enuzak)
		{
			uzakNokta1 = i;
			enuzak = enuzak2;
		}
	}

	//enuzak = başlangıc yarıcapı

	ara1 = 0;
	ara2 = 0;

	//dogru denklemi = (y2-y1)*(x-x2)=(x2-x1)*(y-y2)

	while (kontrolSayac != 0)
	{
		if (k == 1) {
			printf("\n-----Tek nokta girilmistir-----\n\n");
			kontrolSayac = 0;
		}

		//-----------------------------------------------------------------------------------------------
		y_farki = (y[uzakNokta1] - (gy));  //(y2-y1)
		x_farki = (x[uzakNokta1] - (gx)); //(x2-x1)

		if (gy < y[uzakNokta1])
		{
			gy = gy + 0.000001;
			gx = (((x_farki) * (gy - y[uzakNokta1])) / (y_farki)) + x[uzakNokta1];  // (y2-y1)*(x-x2)=(x2-x1)*(y-y2) bu denklemin yazımı.
		}

		else if (gy > y[uzakNokta1])
		{
			gy = gy - 0.000001;
			gx = (((x_farki) * (gy - y[uzakNokta1])) / (y_farki)) + x[uzakNokta1];
		}

		else if (gy == y[uzakNokta1])
		{
			if (gx < x[uzakNokta1])
			{
				gx = gx + 0.000001;
			}
			else
			{
				gx = gx - 0.000001;
			}
		}
		// noktamızı 1 kere kaydırdık
		//-----------------------------------------------------------------------------------------------
		islem++;
		for (i = 0; i < k; i++)
		{
			ara1 = pow((gx - (x[i])), 2);
			ara2 = pow((gy - (y[i])), 2);
			m_uzak2 = sqrt(ara1 + ara2);
			uzaklık[i] = m_uzak2;
			islem++;
		}
		//kaydırdığımız noktaya göre tüm noktaların uzaklıklarını uzaklık[] dizisine atıldı

		for (i = 0; i < k; i++)
		{
			islem++;
			if (i == uzakNokta1) {
				continue;
			}
			if (fabs(uzaklık[i] - uzaklık[uzakNokta1]) <= 0.0001) {
				//uzak nokta ile başka bir noktanın merkeze uzaklığı eşit olursa
				//kısaca cemberin üzerinde 2. noktayı buldu
				uzakNokta2 = i;

				geciciXm = (x[uzakNokta1] + x[uzakNokta2]) / 2;
				geciciYm = (y[uzakNokta1] + y[uzakNokta2]) / 2;

				x[k] = geciciXm;//merkeze aynı uzaklıkta olan 2 noktanın x degeri 
				y[k] = geciciYm;//merkeze aynı uzaklıkta olan 2 noktanın y degeri

				//merkeze aynı uzaklıkta olan 2 noktanın orta noktası alındı 

				y_farki = (y[k] - (gy));
				x_farki = (x[k] - (gx));
				islem++;
				while (kontrolSayac2 != 0) {
					sayac2++;
					//ana merkezi, 2 nokta arasındaki orta noktaya yakınlaştırıyoruz
					if (gy < y[k])
					{
						gy = gy + 0.000001;
						gx = (((x_farki) * (gy - y[k])) / (y_farki)) + x[k];
					}

					else if (gy > y[k])
					{
						gy = gy - 0.000001;
						gx = (((x_farki) * (gy - y[k])) / (y_farki)) + x[k];
					}

					else if (gy = y[k])
					{
						if (gx < x[k])
						{
							gx = gx + 0.000001;
						}
						else
						{
							gx = gx - 0.000001;
						}
					}
					islem++;

					//şuanki merkeze tüm noktaların uzaklıkları diziye yazıyoruz

					for (i = 0; i < k; i++)
					{
						ara1 = pow((gx - (x[i])), 2);
						ara2 = pow((gy - (y[i])), 2);
						m_uzak2 = sqrt(ara1 + ara2);
						uzaklık[i] = m_uzak2;

						islem++;
					}

					//tüm uzaklıkları kontrol ediyoruz;

					for (i = 0; i < k; i++)
					{
						if (i == uzakNokta1) {
							continue;
						}
						else if (i == uzakNokta2) {
							continue;
						}

						if (fabs(uzaklık[i] - uzaklık[uzakNokta1]) <= 0.00001) {
							//merkeze en uzak noktanın mesafesi ile başka bir noktanın mesafesi eşitlenince dögüden çıksin (yani cembe üzerinde 3. nokta)
							kontrolSayac2 = 0;
							kontrolSayac = 0;
						}
						islem++;

					}

					if (fabs(gy - y[k]) <= 0.00001) {
						//otelenen merkez ile 2 uzak nokta arasındaki merkez birbirine çok yakınsa döngüden çıksın
						//bu durum 2 uzak noktanın çap üstünde olması veya çok yakın olması durumu 
						kontrolSayac2 = 0;
						islem++;

					}

					if (sayac == 20000000) {
						//eger dongü bitmezse
						printf("\n-----------HATA-----------\n");
						printf("\n!!!! Noktalari kontrol et !!!!\n");
						printf("\n!!!!\n");
						kontrolSayac2 = 0;

					}

					sayac++;

				}

				kontrolSayac = 0;
			}

		}

		if (sayac == 50000000) {
			//eger dongü bitmezse
			printf("\n-----------HATA-----------\n");
			printf("\nHesaplama sartlara takıilmadi\n");
			printf("\n!!!! Noktalari kontrol et !!!!\n");
			kontrolSayac = 0;
		}


		sayac++;
	}

	for (i = 0; i < k; i++) {
		if (uzaklık[i] > enbuyuk_yaricap) {
			enbuyuk_yaricap = uzaklık[i];
		}
	}


	/*printf("Islem sayisi= %.f",islem);
	printf("\nUST while %.f kez donmustur.\n", sayac );
	printf("ALT while %.f kez donmustur.\n", sayac2);
	printf("dongu toplam %.f kez donmustur.\n",sayac+sayac2);*/

	veriler[0] = gx;
	veriler[1] = gy;
	veriler[2] = uzakNokta1;
	veriler[3] = enbuyuk_yaricap;
}

int main() {

	float x[100] = { 0 }, y[100] = { 0 };
	float  veriler[4] = { 0 };
	double mx = 0, my = 0, yarıcap = 0, uzakNokta = 0; // veriler[4] de tutulan değerler.
	int k = 0, i = 0;

	FILE* dosya;
	dosya = fopen("koordinatlar.txt", "r");

	if ((dosya) == NULL)
	{
		printf("\n****Dosya yok!****\n");
		exit(1);
	}
	else
	{
		printf("\n****Dosya var****\n");
	}

	//txt yi  diziye aktardık
	i = 0;

	while (!feof(dosya))
	{
		fscanf(dosya, " %f %f ", &x[i], &y[i]);
		i++;
	}

	k = i;

	printf("\n Nokta sayisi = %d\n\n", k);

	for (i = 0; i < k; i++) {
		printf("%2d. nokta = %3.f ,%3.f\n", i + 1, x[i], y[i]);
	}
	printf("\n");

	fclose(dosya);

	Hesap(x, y, k, veriler);

	mx = veriler[0];
	my = veriler[1];
	uzakNokta = veriler[2];
	yarıcap = veriler[3];

	printf("\n YARI CAP = %f\n", yarıcap);
	printf("\n MERKEZ   = (%f) , (%f)\n\n\n", mx, my);

	Koordinat_Duzenleme(x, y, k, veriler);

	mx = veriler[0];
	my = veriler[1];

	grafik(x, y, k, mx, my, yarıcap, uzakNokta);

	return 0;
}

