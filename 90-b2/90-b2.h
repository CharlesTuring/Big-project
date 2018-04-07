/*1751367 ��2 ������*/
#pragma once

#define EXTRA_ROW 5

#define MIN_ROW 22
#define MIN_COL 15
#define MAX_ROW 50 //��Ҳ��֪��Ҫ����������Ϊ���ٺã������û��������������޸İ�
#define MAX_COL 50 

//��ŷ���ľ���Ĵ�С
#define BLOCK_ROW 5
#define BLOCK_COL 5



//����ɫ�黹�ǻ���ɫ��Ĳ���
#define DRAW 1
#define ELIMINATE_PAST 0
#define ELIMINATE_CURR 2

//������ת�ķ���
#define ANTI_CLOCKWISE 1
#define CLOCKWISE 0

//��Ϸ�汾
#define CMD 0
#define GUI 1

//��Ļ����ṹ��
struct Cord
{
	int cord_x;
	int cord_y;
};

//��������ṹ��
struct Position
{
	int cord_row;
	int cord_col;
};

//����̨���ڽṹ�壬��¼����̨���ڴ�С
struct Consoleborder
{
	int cols;
	int lines;
};

//cmd�汾��Ϸ����ṹ��
struct Game_area
{
	int display_matrix[53][50] = { 0 };//������ʾ��Ϸ����ľ���
	int matrix_row;
	int matrix_col;
	const char *border[6] = { "��","��","��","��","��","��" };//�߿�����
	Cord orig_cord;
};

//��ʾһ�����鵱ǰ״̬�Ľṹ��
struct State
{
	bool move_allowed= 1;
	bool left_allowed = 1;
	bool right_allowed = 1;
	bool rotate_allowed = 1;
};

//����ṹ��
struct Block
{
	int matrix[BLOCK_ROW][BLOCK_COL]; //�����������һ��5*5�ľ�����
	Position curr_pos; //�������ĵ�ǰ��λ��
	Position last_pos; //���������ϴ�����λ��
	int value; //�÷������������
	const char *style[7] = { "��","��","��","��","��","��","��" }; //������ʽ
	Position central_pos = { 2,2 };
	State state;
};

void print_cmd_game_area(Game_area game_area);
void input_row_col_tetris(int &row, int &col, int Max_row, int Min_row, int Max_col, int Min_col);
void cmd_tetris();
void GUI_tetris();
void draw_block(Block block, Game_area &game_area, int type);
void block_move(Block &block, int direction, Game_area &game_area, int type);
void block_rotate(Block &block, Game_area &game_area, int direction, int type);
bool position_legal(Block block, Game_area game_area);
bool judge_behavior(Block block, Game_area game_area, int type);
void kill_row_fall(Block block, Game_area &game_area, int &total_score, int type);
bool judge_end(Game_area &game_area);
void print_GUI_game_area(Game_area game_area);
void draw_GUI_block(Block block, int value, int cord_x, int cord_y, int type);
void draw_full_block(Block block, Game_area &game_area, int type);
void side_info(int next_num, int total_score);