
inherit ROOM;

void create()
{
	set("short", "�ֵ�");
	set("long", @LONG
����ʯ���̳ɵĵ�·����ɨ�ø�Ǭ����������Сͯ�ڽֵ��ϻ���
׷����ˣ���ֵ������Ǻ�ש���ɵķ��ݣ���λ�������е����ڼ���ǰ
�������졣
LONG
	);
	set("exits", ([ 
		"north" : __DIR__"xzroad1",
		"south" : __DIR__"xzroad3",
		"east" : __DIR__"xzhouse1",
		"west" : __DIR__"xzstore1",
	]));
	set("outdoors", "wudang");
        set("objects", ([
                __DIR__"npc/xiaotong" : 2,
                __DIR__"npc/oldman" : 2,
        ]) );
	setup();
replace_program(ROOM);

}