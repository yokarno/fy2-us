
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "����");
        set("long", @LONG
������һ����Ⱦ�������������ıڶ�������ܣ��ݽ�һ���ټ�������һ
�����ҡ����м���δ��ɵĻ���ɢ�ҵض�����һ�ǵĻ����ϡ����Ϲ�������
����͵�����������Կ�����һ��ʢ���ľջ���
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"juhua",
]));
        set("objects", ([
        __DIR__"obj/desk" : 1,
	__DIR__"npc/manfeng" : 1,
                        ]) );

        setup();
}
void reset()
{
	object *inv;
	object con, item;
	::reset();
	con = present("desk", this_object());
        inv = all_inventory(con);
        if( !sizeof(inv)&& !random(2)) {
	item = new(__DIR__"obj/picture");
	item->move(con);
	}
}