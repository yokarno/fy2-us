inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "Сľ��");
        set("long", @LONG
ľ��ֻ�а�߶���һ����÷����ס���ǰ�ߡ�ǽ�Ϲ��ż���ԡ����
����͸����֦����ԡ���ϡ�һ����ܴӷ������£���ܵľ�ͷ����һ��
ľ���ӣ�ż������ˮ����¡�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"frontyard",
]));
        set("objects", ([
        __DIR__"obj/towel": 1,
                        ]) );
        set("item_desc", ([
                "ľ����": "
                        ���ƺ����԰����Σ������죩������\n",

        ]) );
        setup();
}
void init()
{
        add_action("do_fillwater", "fillwater");
	add_action("do_pull","pull");
	add_action("do_climb","climb");
}
int do_pull()
{
	object me;
	if(query("resource/water"))
		return notify_fail("ľ�����Ѿ����������ˡ�\n");
	me = this_player();
	message_vision("$N���ۣ���һ����ľ���Ӱ���������ð��������ˮ��������������\n",me);
	set("resource/water",1);
	set("liquid/name","��ˮ");
	call_out("remove_water",50);
	return 1;
}

int remove_water()
{
	tell_object(this_object(),"��ˮ���˼��Σ��������ˡ�\n");
	delete("resource/water");
        delete("liquid/name");
	return 1;
}
int do_fillwater(string arg)
{
        object *list, ob;
        int i, can_fillwater;
        string dir;
	if(!query("resource/water")) return 0;
        if( !arg || arg=="" ) return 0;

        if( arg=="skin" || arg=="wineskin" ) {
                list = all_inventory(this_player());
                i = sizeof(list);
                can_fillwater = 0;
                while (i--) {
                  if (((string)list[i]->query("liquid/type") == "alcohol")
 || ((string)list[i]->query("liquid/type") == "water")         ) {
                        ob = list[i];
                        can_fillwater = 1;
                        ob->set("liquid", ([
                                "type": "water",
                                "name": "��ˮ",
                                "remaining": 15,
                                "drunk_apply": 0,
                        ]) );
                        write("���������������ˮ! \n");
                        return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("��û��װˮ�Ķ�����....\n");
                        return 1;
                }
        }
        else {
                write("��Ҫ��ʲô���������ˮ��");
        }
        return 1;
}
int do_climb()
{
	object me,room;
	me = this_player();
	message_vision("$N��ಣ���һ����˳����÷�������ݶ���\n",me);
	room = load_object(__DIR__"roof");
	me->move(room);
	return 1;	

}