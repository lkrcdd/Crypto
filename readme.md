# 암호

### overall concept
- 용어  
plain text : 평문, 원본 데이터  
cipher text : 암호문  
encryption / decryption : 암호화/복호화  
key : 사전에 약속된 value  
복호화 : 합법  
해독 : 합법/불법  

- 암호의 기능
   1. 기밀성(Confidentiality)
   2. 무결성(Integrity)
   3. 인증(Authentication) : 디지털 정체성 식별
   4. 부인 봉쇄(Non-repudiation) : 정보를 보낸 사람이 나중에 정보를 보냈다는 것을 부인하지 못하도록 하는 기능

- 암호 설계 목표
   1. 안정성 확보
      계산적 안전성 : 공격 시 필요한 계산량이 아주 많음  
      증명 가능한 안전성: 수학적으로 어렵다고 증명된 문제로 알고리즘 구성 -> 현실적으로 해결(공격) X. (ex)소인수분해의 어려움, 이산대수 문제의 어려움  
      절대적 안전성: ㄹㅇ무적  
   2. 해독 비용 > 정보의 가치가 되도록  
   3. 암호 해독 시간 > 정보의 유효 기간이 되도록  
   4. Kerckhoffs : 암호 알고리즘보단 키의 비밀 지키자  

- symmetric key
대치 암호  
   단일 문자 대치 : 덧셈, 곱셈, 아핀  
   다중 문자 대치 : 자동 키, Vigenere, hill, Rotor
전치 암호 : rail fence, 열 전치  

- asymmetry key : public & private key
   - message encrypt
      public -> encryption  
      private -> decryption
   - Electronic signature, authentication
      public -> decryption  
      private -> encryption

### 정수론
이상, 이하 - [ ],  초과, 미만 - ( )
특정 연산 == @

- 암호는 정수 집합에서 동작
임호화 키 -> 정수
복호화 키 -> 해당 정수의 역원

##### 항등원 역원
- 항등원 역원
암/복호화 알고리즘의 연산이 덧셈 연산
-> Zn에 속한 모든 정수가 덧셈에 대한 역원
-> Zn 내의 모든 수가 키

암/복호화 알고리즘의 연산이 곱셈
-> 곱셈에 대한 역원을 갖는 원소 집합을 사용해야 함.
-> 확장 유클리드 알고리즘을 이용하여 구할 수 있다.

- 항등원 (identity element)
x @ y = x 인 원소 y
ex) 덧셈 - 0, 곱 - 1

- 역원 (Inverse element)
x @ y = identity 인 원소 y
ex 1) 덧셈 연산에 대한 역원
	x + y = 0 
	∵ y = -x
ex 2) 곱셈 연산에 대한 역원 → 1
	x * y = 1
	∵ y= 1 / x
=> inverse가 있다 == 복호화가 가능하다 == 암호화의 key로써 기능을 할 수 있다

##### 유클리드
- 나눗셈
Binary operator : 2 input 1 output
but 나눗셈은 몫과 나머지를 산출하므로 이항연산이 아님. 이는 관계식으로 표현함.
a = qn + r
q r : 몫/나
a n : 피제/제
암호학에서는 n과 r이 양수여야 함.
그러나 a가 음수인 경우 q r이 음수가 됨
-> q에 -1을 가하고, n을 더한다 -> 일종의 테크닉. 계산해보면 같은 값이 나오는 식이지만 제약조건에 맞게 됨.

- 가분성 Divisibility
n | a -> a % n == 0
n ∤ a -> a%n != 0
property
   1) if ( 𝑎 | 1 ) { 𝑎 = ± 1 }
   2) if ( 𝑎 | 𝑏  &&  𝑏 | 𝑎 ) { 𝑎 = ± 𝑏 }
      b=xa, a=yb
      b=xyb 
      -> xy=1
   3) if (𝑎 | 𝑏  &&  𝑏 | 𝑐 ) { 𝑎 | 𝑐 }
      b = xa, c = yb
      c = y(xa) = (xy)a 
      -> 𝑎 | 𝑐
   4) if( 𝑎 | 𝑏  &&  𝑎 | 𝑐 ) { 𝑎 | 𝑚𝑏 + 𝑛𝑐 }  (단, 𝑚, 𝑛 ∈ Z)
      b = xa, c = ya
      mb + nc = mxa + nya = (mx + ny)a
      -> 𝑚𝑏 + 𝑛𝑐

- gcd
divisor (약수)
common divisor (공통 약수)
greatest common divisor (최대 공통 약수)

- 유클리드 알고리즘
gcd(a, 0) = a
gcd(a, b) = gcd(b, r)  \*(r == a%b)

- 확장 유클리드 알고리즘
베주 항등식?
두 개의 정수 𝒂와 𝒃가 주어졌을 때, 𝐠𝐜𝐝(𝒂, 𝒃)와 함께 다음을 만족하는 다른 두 정수 𝒔와 𝒕를 동시에 계산한다.
𝒔𝒂 + 𝒕𝒃 = 𝐠𝐜𝐝 (𝒂, 𝒃)
=> 코드구현 해볼 것

##### 군환체
- group, ring, field
![alt text](image.png)
1. group
G=<Set, Operator>
Set : finit or infinit
order : number of Set's element
Operator : 1개. 단, 역함수 관계에 있는 연산자는 사용가능
property :
1. Closure : if (a oper b = c) & (a b in Set), c in Set
2. Associativity : 결합 법칙
3. Existence of identity
4. Existence of inverse
5. (if commutative group) commutativity (교환 법칙)

2. Ring
R=<Set, Operator_1, Operator_2>
operator_1 : commutative group's operator
operator_2 : 
닫힘, 결합, 분배 (if commutative R, 교환). 
항등원/역원이 없을수도 있음(역함수 관계에 있는 연산자라도 사용 불가)
property :
1. Closure
2. Associativity
3. (if commutative Ring) commutativity

3. Field
수학에서 일반적으로 사용되는 덧셈/뺄셈, 곱셈/나눗셈 연산의 두 쌍들을 사용할 수 있는 구조이다.
(단, 0으로 나누는 것은 제외)
F=<Set, Operator_1, Operator_2>
operator_1 : commutative group's operator
operator_2 : commutative group's operator without

- Galois Field
1. GF(p^n)
p^n개의 finit set (p : 소수, n : 양의 정수)
(ex) GF(p)
Zp={0~p-1}
operator= + & x, inverse exist(0 제외)

2. GF(2^n)
computing 시 사용하는 set
n bit word set
정수 -> n bits의 block으로 저장 -> 0~2^n-1 -> need mod 2^n
GF(p) : p = 2^n보다 작은 가장 큰 소수
GF(2^n) : n bit field. 2^n-1개 표현가능. bit연산
올림처리 안함. xor
표현식 변환 : bit -> 다항식

𝑓(𝑥) = 𝑎𝑛−1𝑥𝑛−1 + 𝑎𝑛−2 𝑥𝑛−2 + … + 𝑎1𝑥1 + 𝑎0𝑥0
-> 2 field (계수, 다항식(곱/나 시 차수관련))
계수 gf(2) -> 올림 없다는 ㅁ뜻

다항식의 모듈러 연산
f(x) % g(x), g(x)는 기약 다항식이어야함.
기약 다항식은 정해져있음.

다항식 덧셈
5 2 1    3 2 0
00110011 -> x. 올림처리 안함. xor
00101011 -> o
5 3 1 0
=> bit별로 xor 이게 속도훨빠름

다항식 덧셈 항등원 0  

다항식 덧셈 역원 자기자신 -> 뺄덧이 같으므로 뺄셈정의X



다항식 곱셈
-> gf넘는 차수 발생
-> mod 연산 사용
-> gf집합에 맞게 됨

n-1차 다항식 일 때
차수가 넘어간다면
f(x)%(n차다항식(기약다항식의형태))
->gf(2^n)범위에 안착됨

다항식 곱셈 항등원 1 (00000001)
다항식 곱셈 역원 확장유클

왜 비트를 다항식으로 표현?
역원구하려고

군환체부터 지금까지가 bit연산을 위한 빌드업
field에서 첫번쨰연산 덧셈 두번쨰 곱셈
word : nbit의 묶음(단위)

##### 모듈러
대칭 키 암호 구현에 필요한 모듈러 연산의 정의와 특징
모듈러 덧셈과 곱셈 연산의 역원을 정의하는 방법
모듈러 곱셈 연산에서 역원의 존재 가능성 판별
대칭 키 암호에서 모듈러 덧셈과 곱셈 연산의 역원이 필요한 이유

modular
나머지(residue)만 출력

합동(congruence)
the quality of being similar to or in agreement with something

잉여류 (Residue classes) \[a\]n
n으로 나누었을 때 나머지가 a인 정수들의 집합

최소 잉여 집합 Zn (set of least residues modulo)
n에 대한 모듈로 연산 결과의 집합 Zn = {0 ~ (n-1)}

modular congruent 
modular 연산 결과가 같음.
𝑎 ≡ 𝑏 mod 𝑥 : 두 정수 𝑎 와 𝑏 는 “mod 𝑥” 에 대하여 서로 합동이다.
연산자 ≡, ex) 𝟐 ≡ 𝟏𝟐 (𝐦𝐨𝐝 𝟏𝟎)

Property 1
(𝑎 + 𝑏) mod 𝑛 = \[(𝑎 mod 𝑛) + (𝑏 mod 𝑛)\] mod 𝑛

Property 2
(𝑎 − 𝑏) mod 𝑛 = \[(𝑎 mod 𝑛) - (𝑏 mod 𝑛)\] mod 𝑛

Property 3
(𝑎 × 𝑏) mod 𝑛 = \[(𝑎 mod 𝑛) × (𝑏 mod 𝑛)\] mod 𝑛
ex) 100^50 mod 7 
= (100 x 100 x ... x 100) mod 7
=(100 mod 7 x 100 mod 7 x ... x 100 mod 7) mod 7
=(100 mod 7)^50 mod 7
=2^50 mod 7

암호 알고리즘에 모듈러 연산 적용 시 사용되는 𝑎와 𝑏의 값은 일반적 으로 매우 큰 수이다.
따라서, 실제 암호 알고리즘을 구현할 때에는 계산 시 발생하는 오버헤드를 예방하기 위해서 상기 Property 1– 3을 활용한다.

- 모듈러 연산 내에서(Zn 내에서) 덧셈/곱셈의 역원
어떤 정수 a와 그 정수의 덧셈에 대한 역원 b의 합은 모듈로 𝑛에 대하여 0과 합동
𝑎 + 𝑏 ≡ 0 mod 𝑛
a + b = n
-> 𝒃 = 𝒏 − 𝒂

두 정수 a와 b가 아래의 성질을 만족하면 이들은 서로 곱셈에대한 역원
𝒂 × 𝒃 ≡ 𝟏 𝐦𝐨𝐝 𝒏
항상 존재하지 않음.
필요충분조건𝐠𝐜𝐝 𝒏, 𝒂 = 𝟏 즉 a와 n이 서로소

### symmetric key
대칭 키 -> en/decrypt에 같은 키
이를 위해 모듈러 연산이 필요.

- 2가지 암호 구조
stream cipher : 거의 모든 고전 암호
block cipher : 일부 고전 암호 + 모든 현대 암호

##### 단일문자 대치
- Additive cipher
𝐶 = 𝑃 + 𝑘 mod 26
𝑃 = 𝐶 − 𝑘 mod 26
전수조사 공격에 매우 취약

- Multiplicative cipher
𝐶 = 𝑃 × 𝑘 mod 26
𝑃 = 𝐶 × 𝑘−1 mod 26
범위 𝑍*26, 𝑘−1은 k의 곱셈에 대한 역원(역수 아님!)

- affine cipher
𝐶 = 𝑃 × 𝑘1 + 𝑘2 mod 26
𝑃 = 𝐶 − 𝑘2 × 𝑘1−1 mod 26

##### 다중문자 대치
- autokey cipher
- Vigenere cipher
- Hill cipher
   key행렬 통으로봐서 mod했을 때? invertable해야함
   왜? key행렬을 곱함으로써 암호화됨으로
   구조만알아두래 수업범위넘는다구
   def(k%26) != 0 인 원소들만 채운대 키행렬에
- rotor cipher

##### 전치
전치 : 위치 이동
- rail fence : 키 없음. 지그재그
- 열 전치 : 키 있음

##### 현대 블록 암호 체계
n bit 단위 분할. 남으면 padding.
k bit single key.
decrypt func = (encrypt func)^-1
대치(substitution) , 전치(transposition) 중요
substitution base + transposition feature

1. p-box : 전치요소
bit단위로 암호화 수행 위한 요소
permutation 규칙. n비트 워드에 대해 n! 경우의 mapping이 존재.  
key 없음 -> mapping 사전 정의
치환테이블로 구현(예제 별표)
   element value : input position
   element position : output position
Straight P-box : 입력 워드 길이 == 출력 워드 길이 -> 얘만 역함수 존재
Expansion P-box : 입력 워드 길이 < 출력 워드 길이 -> 일부 출력 bit 반복
Compression P-box : 입력 워드 길이 > 출력 워드 길이 -> 일부 입력 bit 소실

inverted table 구하기
1. straight p-box인지 
2. 맞으면 inverted 구하기

2. s-box : 대치요소
m by n matrix
관계식, 행렬, table로 표현가능. 
linear or non-linear s-box
s-box table 별표
입력 비트 수 == 출력 비트 수 면 inverse exist

3. operation : XOR, Shift, Swap etc..
- xor : GF(2) -> {0, 1} -> 올림 버림 -> +, - == xor
- circular shift
- swap 
- split and combine

Confusion : 암호문에서 키를 알아내기 어렵게 하는 성질
Diffusion : 암호문에서 원본 메세지를 알아내기 어렵게 하는 성질


##### DES
Data Encryption Standard. 64bit 블록 암호
key 56bit + parity_check 8bit = 64bit
16 round : 16번 encrypt. 역순으로 decrypt

- component
IP : Initial Permutation, 초기 순열
f_K :각 bit별 transposition와 substitution 연산 수행 함수 -> key 사용
SW : swap func

- En/Decrypt process
Ciphertext = IP^-1(f_K2(SW(f_K1(IP(Plaintext)))))
Plaintext = IP^-1(f_K1(SW(f_K2(IP(Ciphertext)))))

- key generation
10bit main key k -> 8bit sub key k1, k2 

p-box : permutation box. permutation principle. 
ex p10   //permutation. length 10
   input : 1 2 3 4 5 6 7 8 9 10     //input permutation
   output : 3 5 2 7 4 10 1 9 8 6    //output permutation일 때,
   P10 (1010000010) -> (1000001100)    //를 해석해라.
   첫 원소 input 1, output 3
   => input permutaion의 1번째 bit가 output permutaion의 3번째 bit로 간다.

축소 p-box : input n bit, output m bit (n>m). 일부 비트 소실
ex p8
   input : 10 bit
   output : 8 bit

LS-1 : 1bit Circular Left Shift

- process
10bit key -> p10 -> 5bit ls-1, 5bit ls-1 독립적 수행 -> 합병 -> p8 -> k1
10bit key -> p10 -> 5bit ls-1, 5bit ls-1 독립적 수행 -> 합병 -> p8 -> k1

- IP process
M = (IP-1(IP(M))) -> 하나마나. 기억하지말래

- f_K *도면의 해석 중요
transposition & substitution연산 수행
input : 8bit word, Left most & Right most
fK = ( L XOR F( R, SK ), R )
여기서 SK는 Sub Key로서, K1 또는 K2

##### AES

##### 합성암호
대치, 치환, 그리고 기타의 구성요소들을 결합한 복합적인 암호
설계된 블록 암호가 혼돈과 확산의 성질을 갖도록 함
즉, 현대 블록암호는 합성 암호 체계로 설계됨
설계 요소
암호문을 더욱 난수처럼(= 유사 난수) 생성되게 함 -> 패턴 은닉
암호문과 평문 사이의 관계를 더욱 알아내기 힘들게 함 (→ 확산)
라운드 수의 증가는 라운드 키의 개수를 증가시킴으로써 암호문과 키의 관계를 유추하기 어렵게 함 (→ 혼돈)

혼돈(Confusion)
• 암호문과 키의 관계를 숨김
• 이에 따라, 공격자가 암호문을 이용하여 키를 찾는 것을 불가능하게 함
• 암호문을 이용하여 키를 찾고자 하는 공격을 어렵게 하기 위해 키의 단일
비트가 변하면 암호문의 거의 모든 비트들이 변하게 함

확산(Diffusion)
• 암호문과 평문 사이의 관계를 숨김
• 통계 테스트를 사용하여 암호문에 대한 평문을 찾는 공격을 어렵게 함
✓암호문의 각각의 비트나 문자가 평문의 모든 비트나 특정 비트에 의하여
종속적으로 결정되도록 함.
✓예를 들면, 평문의 단일 비트가 바뀐다면, 암호문에 있는 특정 비트 또는
모든 비트가 바뀌게 구성함.

상기 두 성질은 단 한개의 bit만 변하더라도 최대한 많은 bit가 바뀌도록 설계한 성질

라운드(Rounds)
하나의 합성 암호 체계.
각 라운드 별 서브키 사용
• 혼돈과 확산은 S-박스와 P-박스 그리고 기타 구성 요소들을 결합하는
합성 암호를 반복적으로 사용하여 구현됨.
• 이 때, 반복적으로 사용되는 합성 암호를‘라운드’라 함.
• 각 라운드에서는
• 키로부터 키 스케줄(==키 생성 알고리즘)을 통하여 생성된 서로 다른
라운드키(서브키)를 사용함.
• 이 때, 각 라운드에서 생성되는 값을 중간 상태 값(middle text)이라 함.

Feistel 암호
➢역함수가 존재하는 구성요소와 역함수가 존재하지 않는 구성요소
모두를 사용하여 설계(e.g., DES)
아래와 같이 세 가지 타입의 요소(element)로 구성됨.
 자기 자신을 역으로 갖는 것(self-invertible)
 역함수가 존재하는 것(invertible)
 역함수가 존재하지 않는 것(noninvertible) -> 복호화는 어떻게?
 역이 존재하지 않은 구성요소들을 서로 결합하고, 암호 알고리즘과
복호 알고리즘에서 동일한 구성요소를 사용함.
Feistel 암호의 초기 구조
• 어떻게 역이 존재하지 않은 구성요소로 설계한 암호 알고리즘과 복호 알고리즘
이 서로 역관계가 될 수 있는가?
• 암호알고리즘에서 역함수가 존재하지 않는 구성요소의 효과가 복호화 알고리
즘에서 상쇄되도록 함.
• (예) 배타적 논리합(XOR)을 사용
• 암호화 : C1 = P1  f(K)
• 복호화 : P2 = C2  f(K) = P1  f(K)  f(K) = P1
• Feistel 구조에서 믹서는 자기 자신을 역함수로 갖음

Non-Feistel 암호 (AES)
➢역함수가 존재하는 구성요소만을 사용하여 설계(e.g., AES)
 Non-Feistel 암호란?
• 역함수가 존재하는 요소만을 사용하여 설계
• 암호화를 구성하는 각 요소는 복호화를 구성하는 각 요소에 대응됨
 주요 특징
• S-Box는 적절하게 동일한 입출력 개수를 가져야 함
• 축소 혹은 확장 P-박스는 역함수가 존재하지 않기 때문에 사용할 수 없음
• 평문이 반씩 분할될 필요 없음
• XOR, 역이 존재하는 2 x 2 S-Box, 역이 존재하는 단순 P-박스만을 구성요
소로 이용
• 복호화에는 라운드 키를 역순으로 이용

### asymmetry key

### cipher attack
수동적 공격 : just steal
능동적 공격 : steal & analysis & attack

##### 암호 공격 방식(중요)
- cipher text only atk
find P(알고리즘만으로 추론) or K from C
암호문만으로 해독

- known plain text atk
탈취한 P, C 쌍의 일부로 복호화 키를 찾는다.
제한된 Zn(알파벳쓰는 고전암호)에 강함.
text가 아니더라도 data를 통해서 내용 추론도 가능

- chosen plain text atk
암호화 알고리즘(함수)에 접근만 가능(구조는 모름)
-> 암호화가 가능하다 
-> P & C 를 계속 생성해서 known plain text attack

- chosen cipher text atk
복호화 알고리즘(함수)에 접근만 가능(구조는 모름)
-> 복호화가 가능하다 
-> P & C 를 계속 생성해서 known plain text attack


- Brute-force attack
키의 집합 Zn을 안다면, 이에 대해 전수 조사. 
요즘 컴성능 좋아서 효과 좋음.
따라서 Zn이 아주 크도록 설계.

- Statistical attack, pattern attack
단어 출력 빈도, 평문&암호문 패턴 분석 -> Zn범위가 줄어듬.
패턴 : 언어학적인 특징, 문법 등
암호문이 패턴을 감추고 랜덤하게 보이도록 설계


##### attack on stream cipher
키 복구 공격: 키로 복호화
대수적 공격: 연립 방정식으로 해독
구별 공격: 분석을 통해 키 스트림과 난수열을 구별
예측 공격: 키 스트림 일부 획득 시 다음 수열 예측

- 단일 치환 암호 공격
빈도 분석 -> 복호화

- Vigenere 암호 공격 : Kasiski Test
빈도수가 높은 단어는 key block의 주기가 맞물릴 때 동일한 문자열로 암호화됨.
동일한 문자열을 n개(n>=2) 찾아서 distance 산출
-> distance % key block == 0 이다
-> 많은 distance를 찾아서 key block의 길이 도출

- Hill Climbing method
머신 러닝에서도 내부적으로 적용되는 방법
x, y축은 입력값, z축은 함수의 result인 함수공간 그래프
f(x, y) = z 를 그래프로 옮겨놓은 것
  ㄴ scalar function (input : 2dim, output : 1dim)
vector function (input : 2dim, output : 2dim)
=> f(x, y)는 오차 함수로 생각 가능 -> z가 최소화 되는 지점으로
이 때 x는 키값, y는 C, z=P-C
공격자가 암호 알고리즘 알때, 복호화 키 알기 위해 hcm씀
blackbox function : 내부 구조 모름. in/output만 알 수 있다.
local minimum problem : saddle point가 여러 개 생김 -> random init을 여러 번 수행


##### attack on block cipher
- 블록 암호 공격 기법의 종류
차분 공격: 블록 암호의 비선형 함수에 대한 input difference와 output difference의 확률 분포가 균일하지 않음을 이용하는 선택 평문 공격 방법.
선형 공격: 여러 개의 선형 근사식을 이용하며 비선형 근사식을 덧붙이는 방법.
연관 키 공격: 서로 다른 두 개의 키 사이의 연관 관계를 알고 있지만 키 자체를 모를 때, 각 키로부터 발생된 평문/암호문 쌍을 이용하여 키를 알아내는 방법.

- Differential Cryptanalysis -> 표보는거 시험에나옴
차분? 미분의 discrept 버전
미분 : continueus적인 성질
Chosen plain text attack으로 key 해독
   1.analysis algorithm
   2. Chosen plain text attack
   3. key 해독

평문의 차분? 임의의 p1 - p2 -> p1 xor p2 -> p1과 p2사이의 관계 체크
A xor n xor n = A, 상쇠됨
=> ㅊ
일반적인절차는 참고만하래

- Linear Cryptanalysis
Known plain text attack
s-box가 선형 식일 때만 사용가능
-> 실제는 비선형으로 s-box 구성 (linear cryptanalysis 피하려고.)

- Linear Approximation
각 수식은 확률 1/2 + 𝜀 을 만족함. (여기서 𝜀 = 편차) -> 안중요함