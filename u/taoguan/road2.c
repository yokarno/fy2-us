
inherit ROOM;

void create()
{
	set("short", "ʯӢ��ʯ��");
	set("long", @LONG
����վ������ݵ����, ����ɫ������ʯӢ�ҽ������Ѷ���, ����
���ɽɫ���γ�һ������ɫ�ľ�����̧ͷ����ʯ�׾�ͷ����������, ��
Ȼ����������Ѿ������������ºۼ�, ���Բ�ʧ��ׯ����ʥ����Ϣ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : "/u/taoguan/road3",
  "southdown" : "/u/taoguan/road1",
]));
	set("outdoors", "taoguan");
	setup();
	replace_program(ROOM);
}