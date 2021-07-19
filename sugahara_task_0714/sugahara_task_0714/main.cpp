#include<stdio.h>
#include <random>


//第１問
//以下の計算に答えよ。
//1011 + 0101		A.16
// 11     5
//110100 + 11011	A.97
// 64      33
//1011 + 110011		A.74
// 11      63


//第２問
//以下の計算に答えよ。
//FF + FF	A.510
//255  255
//ed + 10	A.253
//237  16
//563 + cd	A.1584
//1379  205


//第３問
//char、int、float、doubleのサイズはそれぞれいくつか答えよ。

//char    8bit
//int     32bit(システムによって異なる)
//float   32bit
//double  64bit

//第４問
//int judge = true;
//if(judge)
//{
//①
//}
//else
//{
//②
//}
//①と②どちらが処理されるか答えよ。

// A. ①

//第５問
//for( int i = 0; i < 100; i = i + 3)
//{
//①
//}
//①の処理が何回実行されるか答えよ。

//#include<stdio.h>
//int main()
//{
//	int count = 0;
//	for (int i = 0; i < 100; i = i+ 3)
//	{
//		count++;
//		printf("i = %d\n", count);
//	}
//}

// A. 34

//第６問
//int i = 0;
//while( i < 100)
//{
// 	i = i + 5;
// 	①
//}
//①の処理は何回実行されるか答えよ。

//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int count = 0;
//	while (i < 100)
//	{
//		i = i + 5;
//
//		count++;
//		printf("i = %d\n", count);
//
//	}
//}

// A. 20

//第７問
//int array[4][5];
//上記配列のサイズはいくつか答えよ。

// A. 01234  の計20
//	  01234
//	  01234
//	  01234

//第８問
//int array[5][20]
//for( int i = 0; i < 5; ++i)
//{
//	for( int j = 0; j < ①; ++j)
//	{
//		array[i][j] = i * ① + j;
//	}
//}
//①には何という数字が入るか答えよ。

// A. 1～20 (21以上になると、配列外参照になるため)

//第９問
//① testFunc( int a)
//{
//    return;
//}
//①にはint,float,voidのどれが正しいか答えよ。

// A.void　(returnで返り値を指定していないため)

//第１０問
//２点間の距離を求める関数を作成してください。
//2点というのは(x, y)座標を持つ2点間の距離になります。

// A.
void VectorAB(float vecAB_X, float pointAX, float pointAY, float vecAB_Y, float pointBX, float pointBY )
{
	vecAB_X = pointAX - pointBX;

    vecAB_Y = pointAY - pointBY;
}

//第１１問
//カード構造体を作成してください。
//このカードはトランプのカードのことです。
//情報として、なんのカードなのかを持っていてください。
//スペードの7である、ハートの13であるなど。
//この構造体には現在の自分の情報を設定する処理と、
//現在の自分の情報を開示する処理を作ってください。



struct Card
{
public:
    //各変数のセッター
    void SetSuit(char newSuit) { this->suit = newSuit; }
    void SetCardNum(int newCardNum) { this->cardNum = newCardNum; }
    void SetcardCheck(bool cheack) { this->cardCheck = cheack; }

    //各変数のゲッター
    char GetSuit() { return this->suit; }
    int GetCardNum() { return this->cardNum; }
    char GetcardCheck() { return this->cardCheck; }

private:
    char suit = NULL;   //カードのスートを表す変数
    int cardNum = NULL;    //カードのナンバーを表す変数
    bool cardCheck = true;  //シャッフル時に、カードを選択済みか判断するbool

};


//トランプの山札の構造体を作成してください。
//その際カードには先ほど作った構造体を使用してください。
//以下の条件を満たしておくこと。
//トランプの枚数は53枚(1 ～ 13 * 4 + ジョーカー1)
//Card card[53];


struct CardBoxDeta
{
public:
    struct Card card[53];

    void CardCreate()
    {
        for (int i = 0; i < 52; i++)
        {
            if (i / 13 == 0)
            {
                card[i].SetSuit('H');

            }
            else if (i / 13 == 1)
            {
                card[i].SetSuit('D');
            }
            else if (i / 13 == 2)
            {
                card[i].SetSuit('S');
            }
            else if (i / 13 == 3)
            {
                card[i].SetSuit('C');
            }
            card[i].SetCardNum((i % 13) + 1);
        }

        card[52].SetSuit('J');

    }
};



//シャッフル機能を実装する。
//card[53]にランダムにカード情報を付与してください。
//card[0]がクラブの6、card[1]がハートの5といったように。
//その際同じカードは存在しないようにしてください。


int main()
{
    int randNum = 0;

    CardBoxDeta cardBoX_Temp;

    cardBoX_Temp.CardCreate();

    CardBoxDeta cardBoX;

    for (int i = 0; i < 53; i++)
    {
        printf("CardDeta suit_%c  num_%d\n", cardBoX_Temp.card[i].GetSuit(), cardBoX_Temp.card[i].GetCardNum());
    }

    printf("\n\n");

    

    for (int i = 0; i < 53; i++)
    {
        while (cardBoX.card[i].GetcardCheck())
        {
            std::random_device rand;

            randNum = rand() % 53;

            if (cardBoX_Temp.card[randNum].GetcardCheck())
            {
                cardBoX_Temp.card[randNum].SetcardCheck(false);
                cardBoX.card[i] = cardBoX_Temp.card[randNum];
            }

        }
        printf("PlayerCard suit_%c  card_num_%d\n", cardBoX.card[i].GetSuit(), cardBoX.card[i].GetCardNum());
    }
}


