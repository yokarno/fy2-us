// butcher.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("�����", ({ "butcher", "da" }) );
        set("title", "��������");
        set("gender", "����" );
        set("age", 35);
        set("long", "һ����������ӣ��ͺ���ļһ\n");
        set("str", 29);
        set("int", 14);
        set("combat_exp", 25000);
        set("attitude", "heroism");
        set_skill("unarmed", 200);
        set("vendor_goods", ([
                "��ͷ": __DIR__"obj/yangtou",
                "��ͷ": __DIR__"obj/zhutou",
                "ţͷ": __DIR__"obj/niutou",
        ]) );

        setup();
        add_money("silver", 2);
        add_money("coin", 500);
        carry_object("/obj/cloth")->wear();

}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) ) {
                case 2:
                        say( "������ֿ�����, Ц�ŵ�����λ"  
                                + RANK_D->query_respect(ob)
                                + "��Ҫ��������? \n");
                        break;
        }
}

 