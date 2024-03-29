### 암호

### concept
- 용어
plain text : 평문, 원본 데이터
cipher text : 암호문
encryption / decryption : 암호화/복호화
key : 사전에 약속된 value
복호화 -> 합법
해독 -> 합법/불법

- 암호의 기능
1. 기밀성(Confidentiality)
2. 무결성(Integrity)
3. 인증(Authentication) : 디지털 정체성 식별
4. 부인 봉쇄(Non-repudiation) : 정보를 보낸 사람이 나중에 정보를 보냈다는 것을 부인하지 못하도록 하는 기능

- Kerckhoffs
암호 알고리즘보단 키의 비밀 지키자

- 암호는 정수 집합에서 동작
임호화 키 -> 정수
복호화 키 -> 해당 정수의 역원

- 항등원 역원
암/복호화 알고리즘의 연산이 덧셈 연산
-> Zn에 속한 모든 정수가 덧셈에 대한 역원
-> Zn 내의 모든 수가 키

암/복호화 알고리즘의 연산이 곱셈
-> 곱셈에 대한 역원을 갖는 원소 집합을 사용해야 함.
-> 확장 유클리드 알고리즘을 이용하여 구할 수 있다.

- symmetric key
대칭 키, en/decrypt에 같은 키. 이를 위해 모듈러 연산이 필요.
대치 암호
   단일 문자 대치
      덧셈, 곱셈, 아핀
   다중 문자 대치
      자동 키, Vigenere, hill, Rotor
전치 암호
   rail fence, 열 전치

stream 암호
block 암호 -> 현대 암호체계

- asymmetry key
public & private key
   1) message encrypt
   public -> encryption
   private -> decryption
   2) Electronic signature, authentication
   public -> decryption
   private -> encryption

### 정수론
이상, 이하 - [ ],  초과, 미만 - ( )
특정 연산 == @

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

- group, ring, field



### 모듈러
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

상기 모듈러 연산의 성질을 왜 이해해야 하는가
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


### 고전 - 대칭키 - 대치 - 단일문자
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

### 고전 - 대칭키 - 대치 - 다중문자
- autokey cipher
- Vigenere cipher
- Hill cipher
   key행렬 통으로봐서 mod했을 때? invertable해야함
   왜? key행렬을 곱함으로써 암호화됨으로
   구조만알아두래 수업범위넘는다구
   def(k%26) != 0 인 원소들만 채운대 키행렬에
- rotor cipher

### 고전 - 대칭키 - 전치
전치 : 위치 이동
- rail fence : 키 없음. 지그재그
- 열 전치 : 키 있음


### 현대 - 대칭키


