inherit NPC;

void create()
{
        set_name("老农", ({ "old farmer", "farmer" }) );
        set("gender", "男性");
        set("age", 46);
        set("long",
		"一位年近五十的农夫。\n"
	);
	set_skill("blade", 10+random(50));
        setup();
        add_money("silver", 1);
	carry_object(__DIR__"obj/liandao")->wield();
}

int accept_object(object who, object ob)
{
        object          book;
	if( ob->name() == "饭篮") {
		say("老农接过饭篮，说道：多谢这位" + RANK_D->query_respect(who) + "，我正饿着呢。\n");
		if( present("rice", ob) && present("qing cai", ob)) {
			say("这位" + RANK_D->query_respect(who) + "象是习武之人，这本书可能对您有用，请收下。\n");
			book = new(__DIR__"obj/book");
			book->move(who);
			return 1;
		}
		else {
			say("老农打开饭篮看了看，说道：咦？这位" + RANK_D->query_respect(who) + 
			"开我的玩笑吗？这里没有饭菜呀。\n");
			return 1;
                }
	}
        return 0;
} 

