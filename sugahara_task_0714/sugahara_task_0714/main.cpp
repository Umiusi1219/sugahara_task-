#include<stdio.h>
#include <random>


//��P��
//�ȉ��̌v�Z�ɓ�����B
//1011 + 0101		A.16
// 11     5
//110100 + 11011	A.97
// 64      33
//1011 + 110011		A.74
// 11      63


//��Q��
//�ȉ��̌v�Z�ɓ�����B
//FF + FF	A.510
//255  255
//ed + 10	A.253
//237  16
//563 + cd	A.1584
//1379  205


//��R��
//char�Aint�Afloat�Adouble�̃T�C�Y�͂��ꂼ�ꂢ����������B

//char    8bit
//int     32bit(�V�X�e���ɂ���ĈقȂ�)
//float   32bit
//double  64bit

//��S��
//int judge = true;
//if(judge)
//{
//�@
//}
//else
//{
//�A
//}
//�@�ƇA�ǂ��炪��������邩������B

// A. �@

//��T��
//for( int i = 0; i < 100; i = i + 3)
//{
//�@
//}
//�@�̏�����������s����邩������B

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

//��U��
//int i = 0;
//while( i < 100)
//{
// 	i = i + 5;
// 	�@
//}
//�@�̏����͉�����s����邩������B

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

//��V��
//int array[4][5];
//��L�z��̃T�C�Y�͂�����������B

// A. 01234  �̌v20
//	  01234
//	  01234
//	  01234

//��W��
//int array[5][20]
//for( int i = 0; i < 5; ++i)
//{
//	for( int j = 0; j < �@; ++j)
//	{
//		array[i][j] = i * �@ + j;
//	}
//}
//�@�ɂ͉��Ƃ������������邩������B

// A. 1�`20 (21�ȏ�ɂȂ�ƁA�z��O�Q�ƂɂȂ邽��)

//��X��
//�@ testFunc( int a)
//{
//    return;
//}
//�@�ɂ�int,float,void�̂ǂꂪ��������������B

// A.void�@(return�ŕԂ�l���w�肵�Ă��Ȃ�����)

//��P�O��
//�Q�_�Ԃ̋��������߂�֐����쐬���Ă��������B
//2�_�Ƃ����̂�(x, y)���W������2�_�Ԃ̋����ɂȂ�܂��B

// A.
void VectorAB(float vecAB_X, float pointAX, float pointAY, float vecAB_Y, float pointBX, float pointBY )
{
	vecAB_X = pointAX - pointBX;

    vecAB_Y = pointAY - pointBY;
}

//��P�P��
//�J�[�h�\���̂��쐬���Ă��������B
//���̃J�[�h�̓g�����v�̃J�[�h�̂��Ƃł��B
//���Ƃ��āA�Ȃ�̃J�[�h�Ȃ̂��������Ă��Ă��������B
//�X�y�[�h��7�ł���A�n�[�g��13�ł���ȂǁB
//���̍\���̂ɂ͌��݂̎����̏���ݒ肷�鏈���ƁA
//���݂̎����̏����J�����鏈��������Ă��������B



struct Card
{
public:
    //�e�ϐ��̃Z�b�^�[
    void SetSuit(char newSuit) { this->suit = newSuit; }
    void SetCardNum(int newCardNum) { this->cardNum = newCardNum; }
    void SetcardCheck(bool cheack) { this->cardCheck = cheack; }

    //�e�ϐ��̃Q�b�^�[
    char GetSuit() { return this->suit; }
    int GetCardNum() { return this->cardNum; }
    char GetcardCheck() { return this->cardCheck; }

private:
    char suit = NULL;   //�J�[�h�̃X�[�g��\���ϐ�
    int cardNum = NULL;    //�J�[�h�̃i���o�[��\���ϐ�
    bool cardCheck = true;  //�V���b�t�����ɁA�J�[�h��I���ς݂����f����bool

};


//�g�����v�̎R�D�̍\���̂��쐬���Ă��������B
//���̍ۃJ�[�h�ɂ͐�قǍ�����\���̂��g�p���Ă��������B
//�ȉ��̏����𖞂����Ă������ƁB
//�g�����v�̖�����53��(1 �` 13 * 4 + �W���[�J�[1)
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



//�V���b�t���@�\����������B
//card[53]�Ƀ����_���ɃJ�[�h����t�^���Ă��������B
//card[0]���N���u��6�Acard[1]���n�[�g��5�Ƃ������悤�ɁB
//���̍ۓ����J�[�h�͑��݂��Ȃ��悤�ɂ��Ă��������B


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


