
inherit ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
地上长着各式个样的花草，其中有在哪里都很难见到的珍
贵药草，在这里就象没人要一样。这里左面是陡峭的山崖，右
面是一个大湖。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : "/u/taoguan/lake1",
  "north" : "/u/taoguan/grassland2",
  "south" : "/u/taoguan/hole4",
]));
	set("outdoors", "taoguan");
	setup();
        replace_program(ROOM);
}
