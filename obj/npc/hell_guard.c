// hell_guard.c

#include <ansi.h>

inherit NPC;
void backattack();
void create()
{
	string *order = ({"子", "丑", "寅", "卯", "辰", "巳", "午", "未", "申", "酉", "戌", "亥"});

	set_name( (order[random(12)]) + "阴鬼卒", ({ "hell guard", "guard" }) );
	set("long", "这是一位来自阴界的守护神，专门担任护法之责。\n");
	set("attitude", "friendly");


	set("max_atman", 100);
	set("atman", 100);
	set("max_mana", 100);
	set("mana", 100);

	set("str", 40);
	set("cor", 30);
	set("cps", 25);

	set("combat_exp", 100000);

	set("chat_chance", 15);
	set("chat_msg_combat", ({
		name() + "喝道：孽障！随我赴阴司受审吧。\n"
	}) );

	set_skill("fork", 90);
	set_skill("parry", 70);
	set_skill("dodge", 50);
	set_skill("move", 70);

	setup();

	carry_object(__DIR__"obj/steel_armor")->wear();
	carry_object(__DIR__"obj/steel_fork")->wield();
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
        if( is_fighting() && (int) this_object()->query("kee") <= 100)
        backattack();
	return ::heal_up() + 1;
}

void leave()
{
	object owner;
	message("vision",
		HIB + name() + "说道：末将奉法主召唤，现在已经完成护法任务，就此告辞！\n\n"
		+ name() + "的身形发出幽暗的蓝光，沈入地下不见了。\n" NOR, environment(),
		this_object() );
        if(objectp(owner=this_object()->query("possessed")))
                owner->add_temp("max_guard",-1);
	destruct(this_object());
}

void invocation(object who, int level)
{
	int i;
	object *enemy;

	set_skill("fork", 90 + random(level/2));
	set_skill("parry", 70 + random(level/2));
	set_skill("dodge", 50 + random(level/2));
	set_skill("move", 70 + random(level/2));
	set("combat_exp", 100000 + random(level/4*level*level));
	message("vision",
		HIB "一道蓝光从地底升起，蓝光中出现一个手执钢叉、面目狰狞的鬼卒。\n\n"
		+ name() + "说道：末将奉法主召唤，特来护法！\n" NOR,
		environment(), this_object() );
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else enemy[i]->kill_ob(this_object());
		}
	}
	set_leader(who);
	set("possessed",who);
}
void backattack()
{
        int i;
        object owner, *enemy;
        if(objectp(owner=this_object()->query("possessed")))
        {
                enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        owner->kill_ob(enemy[i]);
                        enemy[i]->kill_ob(owner);
                }
        }

        }

}

void die()
{
	object owner;
        if(objectp(owner=this_object()->query("possessed")))
                owner->add_temp("max_guard",-1);
	::die();
}
