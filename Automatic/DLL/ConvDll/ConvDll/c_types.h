
  //������������� ����� ������
#define    vt_double         0      //������������
#define    vt_bool           1      //���������  
#define    vt_int            2      //�����

  //����������� ����������
#define    dir_input         0
#define    dir_out           1
#define    dir_inout         2

  //����� ������ run-������� �����
#define    f_InitState       1      //������ ��������� ���������
#define    f_UpdateOuts      2      //�������� ������ �� ��������������� ����
#define    f_GoodStep        3      //�������� ������ �� "�������" ����
#define    f_GetDeri         4      //��������� �������� ������ ������ ���������������� ���������
#define    f_GetAlgFun       5      //��������� �������� ������ ������ �������������� ���������
#define    f_SetState        6      //��������� �������� ���������� ���������� ��������� (����� ���� ��������������)
#define    f_UpdateProps     7      //�������� ������ ���������� (� ������ ����� ������������)
#define    f_GetJacobyState  8      //��������� �������� ���������� ���������� ��������� ��� ������� ��������
#define    f_UpdateJacoby    9      //�������� ������� �����
#define    f_RestoreOuts    10      //�������� ������ ����� �������� (������ ���� ����� ����, �.�. ������ �� ����� ����� ������������)
#define    f_SetAlgOut      11      //��������� ������ �����, ���������� �������������� ����������
#define    f_InitAlgState   12      //��������� ��������� ����������� ��� �������������� ����������
#define    f_Stop           13      //���������� ��� ��������� ������� (����� �������������)
#define    f_InitObjects    14      //������������� ��������, �������� � �.�. (����� ����� ����������) (������ �������������)

  //����� ������� �������������� ������� �����
#define    i_GetBlockType    1      //�������� ��� ����� (��������, ������������ � �.�
#define    i_GetDifCount     2      //�������� ����� ���������������� ����������
#define    i_GetDisCount     3      //���� Result > 0 �� �������������� ���� f_SetState
#define    i_GetAlgCount     4      //�������� ����� �������������� ����������
#define    i_GetCount        5      //�������� ����������� ������\�������
#define    i_GetInit         6      //�������� ���� ����������� ������� �� ������
#define    i_GetPropErr      7      //�������� ������������ ������� ���������� ����� (����� �����������)
#define    i_HaveSpetialEditor  8   //���� - run-������ ����� ������������������ �������� �����

  //���� ������ (��� ����������, ���������� �������, �������)
#define    t_none              0    //��������� ����, � ������� �� ���������
#define    t_src               1    //����-�������� �������
#define    t_din               2    //������������ ����
#define    t_dis               4    //���������� ���� � �����������            // ??? - � ����� �� ��� ���� ������
#define    t_fun               8    //�������������� ����
#define    t_dst              16    //����-�������� ����������
#define    t_del              32    //����� ������������                       // ???
#define    t_ext              64    //�����-��������������                     // ???
#define    t_der             128    //�����-�����������                        // ???
#define    t_imp             256    //�����-��������� ������
#define    t_exp             512    //�����-���������� ������
#define    t_nln            1024    //�����-�������� ���������� ���������

  //��������� ���������� �������
#define    r_Success        0       //��� ������
#define    r_Fail           1       //�������� ������

  //������ - ������� ������� � DLL
#define EXPORTED_FUNC int _stdcall

  //������ ����������
typedef struct {
  char* name;
  int   data_type;
  int   dim[3];
  int   index;
  int   direction;
  char* description;
  void* default_ptr;
  int   data_size;
} ext_var_info_record;

  //������� ���� ��������
  //��� - ������ ������� 
typedef void*  ptr_array[10000000];
  //��� - ������ ������������ �����
typedef double double_array[10000000];
  //��� - ������ ���������
typedef char boolean_array[10000000];
  //��� - ������ ����� �����
typedef int int_array[1000000];

  //�������� ��������� ��� ������� � ����������� ���������� � ������� ��������
typedef struct {
  void*   LayerContext;                  // ��������� �� �������� ��������
    //��������� �������������� - ���������� �����
  char    IntMet;                        // ����� ��������������
  char    LoopMet;                       // ����� ������� ������� ���
  char    IsLoop;                        // ���� ������ �������������� (����� ��� �������) - ��� ����� - True
  int     MaxLoopIt;                     // ������������ ����� �������� ��� ������� ������� ���
  double  AbsErr;                        // ���������� ������
  double  RelErr;                        // ������������� ������
  double  Hmin;                          // ����������� ��� ��������������
  double  Hmax;                          // ������������ ��� ��������������

    //���������, �������� ��� ������������� �������
  char    fPrecition;                    //���� ������ �������������
  char    fOneStep;                      //���� ���������� ������ ���� ��������������
  char    fFirstStep;                    //���� ������� ���� �������

    //���������� ���������� ���������
  double  newstep;  //����� ���������� ��� ��������������
  char    fsetstep;   //���� - ���������� ����� ��� ��������������

    //��� ������ ������������ ��� ���� ����� ���������������� � �������
    //������������������ ������� ����� (�������� ������������� �������� ���. ���������)
    //����� ���������� ������ �� �����   
  void* (_cdecl *FindGlobalObject)(void* ALayerContext,char* aGlobObjectName);
    //���������������� ����� ���������� ������
  void (_cdecl *RegisterGlobalObject)(void* ALayerContext,char* aGlobObjectName,void* aNewObject);
    
    //���� ������������� ���������� ���� 
  char  fNeedIter;                    
    	
} solver_struct;

typedef solver_struct*  p_solver_struct;
