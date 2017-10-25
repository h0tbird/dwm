//--------
// Fonts:
//--------

static const char dmenufont[] = "xos4 Terminus:size=8";
static const char *fonts[] = {
	"Wuncon Siji:size=10", // fc-match "Wuncon Siji:size=10"
	"xos4 Terminus:size=8" // fc-match "xos4 Terminus:size=8"
};

//-------------
// Appearance:
//-------------

static const unsigned int borderpx = 1; // Border pixel of windows
static const unsigned int snap     = 8; // snap pixel
static const Bool showbar          = 1; // 0 means no bar
static const Bool topbar           = 1; // 0 means bottom bar

//---------
// Colors:
//---------

static const char color1[] = "#282a2e"; // Dark gray
static const char color2[] = "#373b41"; // Pale gray
static const char color3[] = "#1d1f21"; // Black gray
static const char color4[] = "#f0c674"; // Pale yellow
static const char color5[] = "#c5c8c6"; // Light gray
static const char color6[] = "#dc322f"; // Soft red
static const char color7[] = "#b294bb"; // Light magenta

static const char *colors[][3] = {
	              /* fg      bg      border */
	[SchemeNorm] = { color2, color3, color1 }, // 1 = normal (grey on black)
	[SchemeSel]  = { color5, color3, color4 }, // 2 = selected (white on black)
	[SchemeUrg]  = { color3, color4, color6 }, // 3 = urgent (black on yellow)
	[3]          = { color1, color3, color1 }, // 4 = darkgrey on black (triangle)
	[4]          = { color3, color1, color1 }, // 5 = black on darkgrey (triangle)
	[5]          = { color7, color1, color1 }, // 6 = magenta on darkgrey
};

//----------
// Tagging:
//----------

static const char *tags[] = {
	"\ue17e", // 1
	"\ue17f", // 2
	"\ue180", // 3
	"\ue181", // 4
	"\ue182", // 5
	"\ue183", // 6
	"\ue184", // 7
	"\ue185", // 8
	"\ue186"  // 9
};

//--------------------------------------
// xprop(1):
//   WM_CLASS(STRING) = instance, class
//   WM_NAME(STRING) = title
//--------------------------------------

static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 1,       0,           -1 },
	{ "Chromium", NULL,       NULL,       1 << 1,       0,           -1 },
	{ "URxvt",    NULL,       "kbcast",   0,            1,           -1 },
	{ "Pinentry", NULL,       NULL,       0,            1,           -1 },
	{ "Gbdfed",   NULL,       NULL,       0,            1,           -1 },
};

//------------
// Layout(s):
//------------

static const float mfact      = 0.5; // Factor of master area size [0.05..0.95]
static const int nmaster      = 2;   // Number of clients in master area
static const Bool resizehints = 0;   // 1 means respect size hints in tiled resizals

static const Layout layouts[] = {
	/* <symbol>        <function> */
	{ " \ue009 ",      tile },
	{ " \ue006 ",      NULL },
	{ " \ue000 ",      monocle },
	{ " \ue00a ",      htile },
};

//------------------
// Key definitions:
//------------------

#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

//-----------
// Commands:
//-----------

static char dmenumon[2] = "0";
static const char *dmenucmd[] = { "dmenu_run", "-hist", "/home/marc/.dmenu.history", "-fn", dmenufont, "-nb", color3, "-nf", color2, "-sb", color3, "-sf", color5, NULL };
static const char *termcmd[]  = { "urxvtc", NULL };
static const char *zoomin[]   = { "zoom.sh", "in", NULL };
static const char *zoomout[]  = { "zoom.sh", "out", NULL };
static const char *zoom1[]    = { "zoom.sh", "1", NULL };
static const char *zoom2[]    = { "zoom.sh", "2", NULL };
static const char *zoom3[]    = { "zoom.sh", "3", NULL };
static const char *zoom4[]    = { "zoom.sh", "4", NULL };
static const char *zoom5[]    = { "zoom.sh", "5", NULL };
static const char *zoom6[]    = { "zoom.sh", "6", NULL };
static const char *zoom7[]    = { "zoom.sh", "7", NULL };
static const char *kbcast[]   = { "kbcast.sh", NULL };

//-------
// Keys:
//-------

static Key keys[] = {
   /* <modifier>                    <key>      <function>      <argument> */
    { MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
    { MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
    { MODKEY|ControlMask,           XK_j,      spawn,          {.v = zoomin } },
    { MODKEY|ControlMask,           XK_k,      spawn,          {.v = zoomout } },
    { MODKEY|ControlMask,           XK_q,      spawn,          {.v = zoom1 } },
    { MODKEY|ControlMask,           XK_w,      spawn,          {.v = zoom2 } },
    { MODKEY|ControlMask,           XK_e,      spawn,          {.v = zoom3 } },
    { MODKEY|ControlMask,           XK_r,      spawn,          {.v = zoom4 } },
    { MODKEY|ControlMask,           XK_t,      spawn,          {.v = zoom5 } },
    { MODKEY|ControlMask,           XK_y,      spawn,          {.v = zoom6 } },
    { MODKEY|ControlMask,           XK_u,      spawn,          {.v = zoom7 } },
    { MODKEY,                       XK_minus,  spawn,          {.v = kbcast } },
    { MODKEY,                       XK_b,      togglebar,      {0} },
    { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
    { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
    { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
    { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
    { MODKEY,                       XK_y,      setmfact,       {.f = -0.05} },
    { MODKEY,                       XK_o,      setmfact,       {.f = +0.05} },
    { MODKEY,                       XK_Return, zoom,           {0} },
    { MODKEY,                       XK_Tab,    view,           {0} },
    { MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
    { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
    { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
    { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
    { MODKEY,                       XK_v,      setlayout,      {.v = &layouts[3]} },
    { MODKEY,                       XK_space,  setlayout,      {0} },
    { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
    { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
    { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
    { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
    { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
    TAGKEYS(                        XK_1,                      0)
    TAGKEYS(                        XK_2,                      1)
    TAGKEYS(                        XK_3,                      2)
    TAGKEYS(                        XK_4,                      3)
    TAGKEYS(                        XK_5,                      4)
    TAGKEYS(                        XK_6,                      5)
    TAGKEYS(                        XK_7,                      6)
    TAGKEYS(                        XK_8,                      7)
    TAGKEYS(                        XK_9,                      8)
    { MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

//---------------------
// Button definitions:
//---------------------

/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
   /* <click>               <event mask>    <button>        <function>      <argument> */
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
    { ClkWinTitle,          0,              Button2,        zoom,           {0} },
    { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
