// liuh-ken.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N使一招「黑虎掏心」，对准$n的$l「呼」地一拳",
		"force":		40,
		"parry":		20,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N扬起拳头，一招「泰山压顶」便往$n的$l招呼过去",
		"force":		30,
		"parry":		10,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N左手虚晃，右拳「中宫直进」便往$n的$l击出",
		"force":		30,
		"parry":		10,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N步履一沉，左拳拉开，右拳使出「老汉推车」击向$n$l",
		"force":		30,
		"parry":		20,
		"damage_type":	"瘀伤"
	]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练少林长拳必须空手。\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	me->receive_damage("kee", 30);
	return 1;
}
int effective_level() { return 6;}

string *parry_msg = ({
        "$n以守为攻，一招「反客为主」，猛击$N握$w的手腕。\n",
});

string *unarmed_parry_msg = ({
        "$n左拳击下，右拳自保，一招「过桥抽板」，将$N封于尺外。\n",

});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
	return 0;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 0;
}

string perform_action_file(string action)
{
        return CLASS_D("bonze") + "/changquan/" + action;
}
