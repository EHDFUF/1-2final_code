#include <stdio.h>
#include <stdint.h>

void CH11_1(void) // 배열 정의 및 접근
{
	// 변수가 여러개 만들어질 때의 관리어려움/유사코드 증가 문제를 배열을 통해 해결
	// 배열 : 다수의 변수선언 가능 (1,2차원 있지만 1차원만) 

	int array1[4]; // int자료형 4개의 길이를 갖는 배열 ex) float array1[4] 이면 float형 1차원 배열인데 길이는 4
	array1[0] = 20;
	array1[2] = 10;
	array1[1] = 30;
	array1[3] = 40; 

	int sum = 0;

	for (int i = 0; i < (sizeof(array1) / sizeof(int)); i++)
		sum += array1[i];
	printf("sum값 = %d\n\n", sum);
	return;

}

void CH11_2(void) // 배열 정의 + 초기값 설정 
{
	int array1[5] = { 1,2,3,4,5 }; int array2[] = { 1,2,3,4,5 }; //컴파일 거치면 같은 문장
	int array3[5] = { 1,2 };

	for (int i = 0; i < (sizeof(array1) / sizeof(int)); i++)
		printf("%d ", array1[i]);
	printf("\n");
	for (int i = 0; i < (sizeof(array2) / sizeof(int)); i++)
		printf("%d ", array2[i]);
	printf("\n");
	for (int i = 0; i < (sizeof(array3) / sizeof(int)); i++)
		printf("%d ", array3[i]); // 1 2 0 0 0 선언안한부분은0으로됨
	printf("\n"); printf("\n");
	return;

}

void CH11_3(void) // char형 배열에 문자열 저장 및 NULL
{
	char str_array[14] = "Good Morning!"; //하게 되면 str_array[0] = G 로 인덱스마다 알파벳이 순차적으로 저장되고 문자열 끝에는 NULL = '\0' 이 삽입되기에 배열 끝부분에 '\0'이 저장됨
	// so str = {'a','b','c'} (얘는 문자 배열) 와 str[] = "abc" 의 경우 후자는 컴파일 과정에서 배열 끝부분에 '\0'이 저장됨 (얘는 문자열)
	printf("str크기 = %d\n", sizeof(str_array) / sizeof(int));
	printf("배열 NULL 정수형 출력 = %d\n", str_array[13]);
	int i = 0;
	while (str_array[i] != '\0')
	{
		printf("%c", str_array[i]);
		i++;
	}
	printf("배열 출력 = %s\n\n", str_array);
	// NULL 아스키코드 0 / 공백 아스키코드 32
	// 문자열 끝에 NULL이 필요한 이유는 문자열 끝 판단을 위해서(문자열 중간중간에 \0 삽입하면 거기까지만 출력함 + scanf 데이터 수 구별은 공백 기준으로 함
	return;
}

void  CH12_1(void) // 포인터 연산자 &, *
{
	// & : 주소값 저장 연산자, * : 주소값이 가리키는 변수 값 접근 연산자
	// so if 변수 num의 주소 값 저장을 위한 포인터변수 pnum을 정의하려면 
	int num = 7; 
	int* pnum; //주소값이 가리키는 변수 값 접근을 위한 변수 선언 + int형 변수를 가리킴
	pnum = &num; //pnum은 num의 주소 값을 가리켜야 하므로 num변수 앞에 &연산자 사용(포인터 변수 크기는 주소 값 크기를 따라감)

	int* pnum1; // pnum1 is pointer to int valuable
	// &는 주소값을 함수처럼 반환하므로 반환값을 저장할 변수가 필요함 그 변수는 당연히 포인터변수
	pnum1 = &num;

	int new_num = 10; 
	int* new_pointer = &new_num;
	*new_pointer = 20; // new_pointer가 가리키는 주소값에 해당하는 변수에서 10->20의 역할을 수행함
	printf("new_pointer를 활용한 new_num 10->20 수행 결과 : %d\n\n", *new_pointer); //new_pointer는 현재 &new_num을 통해 new_num의 주소값을 저장하게 되어있으므로 *빼고 new_pointer를 출력할 시 new_num의 주소값을 출력하게 된다

}

void CH12_2(void) // *(주소값 활용하여 변수 접근)을 통해 변수값 변경
{
	int num1 = 10; int num2 = 20;
	int* pointer_num; // int형 포인터 의 변수는 pointer_num으로 정함 -> pointer_num is pointer to int
	
	pointer_num = &num1; 
	*pointer_num += 30; // *(num1의 주소값 접근하고 해당 위치 변수 접근) 을 통해 30 증가연산자

	pointer_num = &num2; 
	*pointer_num -= 10;
	// &연산자 갱신을 통해 언제든지 pointer_num이 어떠한 주소를 가리킬지 바꿀 수 있다(&을 통해) BUT 포인터 변수의 자료형(+BYTE 크기)에 따라 갱신이 제한될 수 있다
	printf("num1 = 10, num2 = 20이 *연산자를 통해 다음 값으로 변경됨 %d %d\n\n", num1, *pointer_num);

}

void CH12_3(void) // 포인터 변수 주의
{
	//int* ptr; // ptr is poiner to int 
	//*ptr = 125; // 주소값을 활용해 변수 접근하고 해당 변수에 125 저장 BUT 주소값이 명시가 안됨 SO 저장된 변수의 주소값이 어디인지 모르니거니와 어디에 저장된지 영원히 알 수 없음 

	// SO 잘못된 포인터 연산 정의를 막기 위해 NULL을 저장하기도 함 
	int* ptr1 = NULL; // pointer to int : ptr1은 현재 어떠한 주소값도 가리키지 않는다는 것을 명시함
	printf("ptr1의 주소값 : %d", ptr1); // NULL이라서 출력이안되는건가? 
}

void CH13_1(void) // 배열의 이름 ? = 배열 첫번째 요소의 주소값
{
	int arr[] = { 0,1,2 };
	printf("배열의 이름 : %p\n", arr);
	printf("배열 첫 번째 요소의 주소값 : %p\n", &arr[0]); // 배열의 이름과 배열 첫번째 요소의 주소값이 같다는 것을 알 수 있음 
	printf("배열 두 번째 요소의 주소값 : %p\n", &arr[1]);
	printf("배열 세 번째 요소의 주소값 : %p\n", &arr[2]);

	// 배열의 이름으로 주소값 변경 불가능 BUT 포인터 변수를 통해 주소값 변경 가능
}

void CH13_2(void)
{
	int arr[] = { 15,25,35 };
	int* ptr = &arr[0]; // == int* ptr = arr; because arr의 이름이 arr[0] 의 주소값 <- 상수 와	 동일하기 때문

	printf("%d %d\n", ptr[0], arr[0]);
	printf("%d %d\n", ptr[1], arr[1]);
	printf("%d %d\n", ptr[2], arr[2]);
	printf("%d %d\n", *ptr, *arr);
	return;
}

void CH13_3(void) // 해당 포인터 대상으로 한 증감연산
{
	int i; double d;
	int* ptr_i = &i; 
	double* ptr_d = &d;

	printf("%p %p\n", ptr_i + 1, ptr_i + 2); // 포인터 자료형에 따른 주소값의 
	ptr_i++;
	printf("%p\n", ptr_i); // 포인터 변수 대상 증감 연산은 sizeof(자료형)의 크기만큼 증감됨
}

// 배열-포인터 관계를 일반화하면 arr[i] <- 첨자를 통해 값 접근 = *(arr + i) 주소값 활용 포인터를 통해 값 접근

void CH13_4(void) // 두가지 형태의 문자열 *시험
{
	char str1[] = "My string"; // str1은 문자 배열이 아닌 문자열 
	char* stcr2 = "My string"; // str2는 포인터 변수이고 주소값은 "My_string"의 **자동 할당된** 주소값 

	char* str = "Your Team"; // str is pointer to char and address value is auto allocated value
	str = "Our Team"; // str is pointer to char and address value is changed (auto allocated value_Your -> auto allocated value_Our)
}

void CH13_5(void) // 상수 형태의 문자열
{
	char* str = "Const string"; // 문자열 저장이므로 주소값은 자동할당
	//char* str = 0x1234; //자동할당이 아닌 지정할당
}

void CH13_6(void) // 포인터 배열
{
	int num1 = 10; 
	int num2 = 20; 
	int num3 = 30;
	int* arr[3] = { &num1, &num2, &num3 }; // * <- arr[0]은 num1의 주소값을 통해 값 접근함
	printf("%d\n", *arr[0]);
	printf("%d\n", *arr[1]);
	printf("%d\n", *arr[2]);
	return;
}
// *p 대신 p[] 도 가능 왜냐하면 매개변수 면에서는 동일선상에 놓임
void CH14_1(int *p, int len) // 매개변수의 원리 : 복사 -> 포인터변수를 활용하기 // 배열 전체 복사가 아닌 배열 이름(p[0]의 주소값)만 접근하여 값 활용하는 것이 메모리효율 면에서 이점을 가져올 수 있음
{  
	for (int i = 0; i < len; i++)
		printf("%d ", p[i]);
	printf("\n");
}

void CH14_1_active(void) //CH14_1 실행
{
	int arr1[] = { 1,2,3 };
	int arr2[] = { 1,2,3,4,5 };
	CH14_1(arr1, sizeof(arr1) / sizeof(int));
	CH14_1(arr2, sizeof(arr2) / sizeof(int));
}

void CH14_2(int num) // call-by-value : 단순 값 전달 형태 함수호출
{
	// 외부변수:Global valuable 은 접근 불가 -> // 함수 내의 값이 외부에 영향을 주지 않는다
}

void CH14_3(int* p) // call-by-reference : 메모리 접근 사용 참조값 전달
{
	// 외부변수:Global valubalbe 은 접근 가능 -> // 함수 내의 값이 외부에 영향을 줄 수 있다 
}

void CH14_2_example(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	printf("a b : %d %d\n", a, b);
}

void CH14_2_example_active(void)
{
	int num1 = 10;
	int num2 = 20;
	printf("num1 num2 : %d %d\n", num1, num2);
	CH14_2_example(num1, num2);
	printf("num1 num2 : %d %d\n", num1, num2); // 함수호출 전후로 값 변화가 없다 = call-by-value가 외부에 영향을 안준다
	return;
}

void CH14_3_example(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("a b : %d %d\n", *a, *b);
}

void CH14_3_example_active(void)
{
	int num1 = 10;
	int num2 = 20;
	printf("num1 num2 : %d %d\n", num1, num2);
	CH14_3_example(&num1, &num2);
	printf("num1 num2 : %d %d\n", num1, num2);
	return;
}

void CH14_4(void) // scanf의 &연산자
{
	int num;
	scanf("%d", &num); // scanf도 엄연한 함수기 때문에 외부에서 선언된 변수를 접근하기 위해서는 주소값을 알아야학기 때문
	int arr[] = NULL;
	scanf("%s", arr); // 해당 접근 변수가 배열이고 배열은 배열 이름 자체가 주소값이기 때문에 &을 안쓴다
}

void CH14_5_alpha(void) // 포인터 변수의 참조대상에 대한 const 선언 **매우중요**
{
	int num = 20;
	const int* pnum = &num; // pnum is pointer to constant intiger // 주소값을 활용해서 변수값 변경하는 것이 const화

	// 포인터 변수 참조대상 const가 된 경우 주소값에 해당하는 변수에서 직접 값을 변경해야함
	// == pnum을 활용해서 값 변경이 const 된 것
	
	// *ptr = 30; 실패
	num = 40; // 성공
}

void CH14_5_beta(void)
{
	int num = 20;
	int* const pnum = &num; // pnum is constant pointer to intiger // 포인터변수값 상수화 

	// ptr = &num; 실패
	*pnum = 40; // 성공 

	const int* const pnum = &num; // 두 개 동시
}

void main(void)
{
	CH14_3_example_active();
	return;
}	