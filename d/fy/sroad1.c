// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ROOM;
void create()
{
        set("short", "Сɽ������");
        set("long", @LONG
�����Ƿ��Ƴǣ�������ʱ����ԼԼ�ػ����Կ������Ƴǵĺ�ɫ������
��������һ����ͺͺ��Сɽ�£������ѱ�·��������̤����һ������
·��·�����߻�����һЩ���˸ߵĽ���é�ݡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "eastup" : __DIR__"sroad2",
  "north" : __DIR__"road0",
  "south" : "/d/manglin/edge2",
]));
        set("objects", ([
        __DIR__"obj/grass" : 1,
                        ]) );
        set("outdoors", "fengyun");
        setup();
}

void reset()
{
object con, item, *inv;
::reset();
if( con = present("grass",this_object()))
if( inv = all_inventory(con))
if( !sizeof(inv))
	{
	item = new(__DIR__"obj/9whip");
	item->move(con);
	}	
}
