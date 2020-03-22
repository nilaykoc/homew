/* ödevv3.cpp 
* bu program bir kurbağa nehri karşıdan karşıya geçmek için kaç farklı yoldan geçeceğini bulur
* Kurbağa sadece ileri doğru ve tek bir seferde rastgele olarak 
*1, 2 veya 3 sonraki taşa zıplamaktadır.
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>

using namespace std;

//aşağıdaki satırları yoruma alarak kodunuzu farklı şekillerde test edebilirsiniz.
#define _TEST_ITERATIVE_
#define _TEST_RECURSIVE_

// Bu odevde global veya statik degisken tanimlanamaz!!!

/* Ozyinelemeli olarak zip zip kurbaganin kac farkli yoldan gittigini bulan fonksiyondur.
 * Bu fonksiyon icinde for ve while kullanamazsiniz ve en az bir kez recursiveFunction
 * fonksiyonu cagri yapilmalidir.
 */
long long recursiveFunction(int n) // fonksiyon dondurup yapar
{

	if (n==0) // 1 2 0 ozel durum basecase dir
		return 1;
	if (n == 2)
		return 2;
	if (n == 1)
		return 1;

	return (recursiveFunction(n - 3) + recursiveFunction(n - 2)) + recursiveFunction(n - 1); //öncekileri toplayarak ilerler
}

/* Yinelemeli olarak zip zip kurbaganin kac farkli yoldan gittigini bulan fonksiyondur.
 * Bu fonksiyon icinde for ve while dongusu kullanilmalidir.
 * Bu fonksiyon icinde baska bir fonksiyona (kendisi dahil) cagri yapilamaz.
 */
long long iterativeFunction(int n) // iterative fonksiyondur
{
	    long long a = 1; // a, b ve c özel durumdur 
		long long b = 1;
		long long c = 2;
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;
		for (int i = 3; i <= n; i++) // özel durumlardan dolayı 3 ten başlanır
		{

			int d = a + b + c; 
			a = b;
			b = c;
			c = d;
		}
		return c;
}

	


int main()
{
	const int MAX_NUMBER_OF_STONES{ 72 };

	cout << setfill(' ');
	int n;
	cout << "sayi giriniz";
	cin >> n;
	cout << "yol sayisi:" << recursiveFunction(n)<<endl;
	cout.imbue(locale(""));

	for (auto i = 1; i <= MAX_NUMBER_OF_STONES; ++i)
	{

#ifdef _TEST_ITERATIVE_
		{
			long long tempResult = { 0 };

			auto start = std::chrono::steady_clock::now();
			tempResult = iterativeFunction(i);
			auto stop = std::chrono::steady_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();


			cout << "iterative" << setw(4) << i << " -> " << tempResult << " ( " << duration << "us )\n";
		}
#endif

#ifdef _TEST_RECURSIVE_
		{
			long long tempResult = { 0 };

			auto start = std::chrono::steady_clock::now();
			tempResult = recursiveFunction(i);
			auto stop = std::chrono::steady_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

			cout << "recursive" << setw(4) << i << " -> " << tempResult << " ( " << duration << "us )\n\n";
		}
#endif

	}

	return 0;
}
