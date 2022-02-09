/* Include files */

#include "RocketSim_sfun.h"
#include "c4_RocketSim.h"
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c4_emlrtMCI = { 122,/* lineNo */
  13,                                  /* colNo */
  "rng",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pName */
};

static emlrtMCInfo c4_b_emlrtMCI = { 158,/* lineNo */
  17,                                  /* colNo */
  "eml_rand_mt19937ar",                /* fName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar.m"/* pName */
};

static emlrtRSInfo c4_emlrtRSI = { 7,  /* lineNo */
  "Calculate Drag Force/MATLAB Function",/* fcnName */
  "#RocketSim:240"                     /* pathName */
};

static emlrtRSInfo c4_b_emlrtRSI = { 12,/* lineNo */
  "Calculate Drag Force/MATLAB Function",/* fcnName */
  "#RocketSim:240"                     /* pathName */
};

static emlrtRSInfo c4_c_emlrtRSI = { 17,/* lineNo */
  "Calculate Drag Force/MATLAB Function",/* fcnName */
  "#RocketSim:240"                     /* pathName */
};

static emlrtRSInfo c4_d_emlrtRSI = { 39,/* lineNo */
  "Calculate Drag Force/MATLAB Function",/* fcnName */
  "#RocketSim:240"                     /* pathName */
};

static emlrtRSInfo c4_e_emlrtRSI = { 54,/* lineNo */
  "rng",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo c4_f_emlrtRSI = { 113,/* lineNo */
  "rng",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo c4_g_emlrtRSI = { 114,/* lineNo */
  "rng",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo c4_h_emlrtRSI = { 116,/* lineNo */
  "rng",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo c4_i_emlrtRSI = { 118,/* lineNo */
  "rng",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo c4_j_emlrtRSI = { 120,/* lineNo */
  "rng",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo c4_k_emlrtRSI = { 273,/* lineNo */
  "rng",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo c4_l_emlrtRSI = { 275,/* lineNo */
  "rng",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo c4_m_emlrtRSI = { 277,/* lineNo */
  "rng",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo c4_n_emlrtRSI = { 278,/* lineNo */
  "rng",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo c4_o_emlrtRSI = { 26,/* lineNo */
  "eml_rand_mt19937ar_stateful",       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand_mt19937ar_stateful.m"/* pathName */
};

static emlrtRSInfo c4_p_emlrtRSI = { 69,/* lineNo */
  "eml_rand_mt19937ar",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar.m"/* pathName */
};

static emlrtRSInfo c4_q_emlrtRSI = { 26,/* lineNo */
  "eml_rand_mcg16807_stateful",        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand_mcg16807_stateful.m"/* pathName */
};

static emlrtRSInfo c4_r_emlrtRSI = { 49,/* lineNo */
  "eml_rand_mcg16807",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand_mcg16807.m"/* pathName */
};

static emlrtRSInfo c4_s_emlrtRSI = { 42,/* lineNo */
  "string",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\string.m"/* pathName */
};

static emlrtRSInfo c4_t_emlrtRSI = { 38,/* lineNo */
  "fprintf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"/* pathName */
};

static emlrtRSInfo c4_u_emlrtRSI = { 66,/* lineNo */
  "fprintf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"/* pathName */
};

static emlrtRSInfo c4_v_emlrtRSI = { 114,/* lineNo */
  "rand",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\randfun\\rand.m"/* pathName */
};

static emlrtRSInfo c4_w_emlrtRSI = { 41,/* lineNo */
  "eml_rand",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand.m"/* pathName */
};

static emlrtRSInfo c4_x_emlrtRSI = { 43,/* lineNo */
  "eml_rand",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand.m"/* pathName */
};

static emlrtRSInfo c4_y_emlrtRSI = { 45,/* lineNo */
  "eml_rand",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand.m"/* pathName */
};

static emlrtRSInfo c4_ab_emlrtRSI = { 15,/* lineNo */
  "eml_rand_shr3cong_stateful",        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand_shr3cong_stateful.m"/* pathName */
};

static emlrtRSInfo c4_bb_emlrtRSI = { 29,/* lineNo */
  "eml_rand_shr3cong",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand_shr3cong.m"/* pathName */
};

static emlrtRSInfo c4_cb_emlrtRSI = { 64,/* lineNo */
  "eml_rand_shr3cong",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand_shr3cong.m"/* pathName */
};

static emlrtRSInfo c4_db_emlrtRSI = { 15,/* lineNo */
  "eml_rand_mt19937ar_stateful",       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand_mt19937ar_stateful.m"/* pathName */
};

static emlrtRSInfo c4_eb_emlrtRSI = { 51,/* lineNo */
  "eml_rand_mt19937ar",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar.m"/* pathName */
};

static emlrtRSInfo c4_fb_emlrtRSI = { 151,/* lineNo */
  "eml_rand_mt19937ar",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar.m"/* pathName */
};

static emlrtRSInfo c4_gb_emlrtRSI = { 257,/* lineNo */
  "eml_rand_mt19937ar",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar.m"/* pathName */
};

static emlrtRSInfo c4_hb_emlrtRSI = { 263,/* lineNo */
  "eml_rand_mt19937ar",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar.m"/* pathName */
};

static emlrtRSInfo c4_ib_emlrtRSI = { 268,/* lineNo */
  "eml_rand_mt19937ar",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar.m"/* pathName */
};

static const uint32_T c4_uv[625] = { 5489U, 1301868182U, 2938499221U,
  2950281878U, 1875628136U, 751856242U, 944701696U, 2243192071U, 694061057U,
  219885934U, 2066767472U, 3182869408U, 485472502U, 2336857883U, 1071588843U,
  3418470598U, 951210697U, 3693558366U, 2923482051U, 1793174584U, 2982310801U,
  1586906132U, 1951078751U, 1808158765U, 1733897588U, 431328322U, 4202539044U,
  530658942U, 1714810322U, 3025256284U, 3342585396U, 1937033938U, 2640572511U,
  1654299090U, 3692403553U, 4233871309U, 3497650794U, 862629010U, 2943236032U,
  2426458545U, 1603307207U, 1133453895U, 3099196360U, 2208657629U, 2747653927U,
  931059398U, 761573964U, 3157853227U, 785880413U, 730313442U, 124945756U,
  2937117055U, 3295982469U, 1724353043U, 3021675344U, 3884886417U, 4010150098U,
  4056961966U, 699635835U, 2681338818U, 1339167484U, 720757518U, 2800161476U,
  2376097373U, 1532957371U, 3902664099U, 1238982754U, 3725394514U, 3449176889U,
  3570962471U, 4287636090U, 4087307012U, 3603343627U, 202242161U, 2995682783U,
  1620962684U, 3704723357U, 371613603U, 2814834333U, 2111005706U, 624778151U,
  2094172212U, 4284947003U, 1211977835U, 991917094U, 1570449747U, 2962370480U,
  1259410321U, 170182696U, 146300961U, 2836829791U, 619452428U, 2723670296U,
  1881399711U, 1161269684U, 1675188680U, 4132175277U, 780088327U, 3409462821U,
  1036518241U, 1834958505U, 3048448173U, 161811569U, 618488316U, 44795092U,
  3918322701U, 1924681712U, 3239478144U, 383254043U, 4042306580U, 2146983041U,
  3992780527U, 3518029708U, 3545545436U, 3901231469U, 1896136409U, 2028528556U,
  2339662006U, 501326714U, 2060962201U, 2502746480U, 561575027U, 581893337U,
  3393774360U, 1778912547U, 3626131687U, 2175155826U, 319853231U, 986875531U,
  819755096U, 2915734330U, 2688355739U, 3482074849U, 2736559U, 2296975761U,
  1029741190U, 2876812646U, 690154749U, 579200347U, 4027461746U, 1285330465U,
  2701024045U, 4117700889U, 759495121U, 3332270341U, 2313004527U, 2277067795U,
  4131855432U, 2722057515U, 1264804546U, 3848622725U, 2211267957U, 4100593547U,
  959123777U, 2130745407U, 3194437393U, 486673947U, 1377371204U, 17472727U,
  352317554U, 3955548058U, 159652094U, 1232063192U, 3835177280U, 49423123U,
  3083993636U, 733092U, 2120519771U, 2573409834U, 1112952433U, 3239502554U,
  761045320U, 1087580692U, 2540165110U, 641058802U, 1792435497U, 2261799288U,
  1579184083U, 627146892U, 2165744623U, 2200142389U, 2167590760U, 2381418376U,
  1793358889U, 3081659520U, 1663384067U, 2009658756U, 2689600308U, 739136266U,
  2304581039U, 3529067263U, 591360555U, 525209271U, 3131882996U, 294230224U,
  2076220115U, 3113580446U, 1245621585U, 1386885462U, 3203270426U, 123512128U,
  12350217U, 354956375U, 4282398238U, 3356876605U, 3888857667U, 157639694U,
  2616064085U, 1563068963U, 2762125883U, 4045394511U, 4180452559U, 3294769488U,
  1684529556U, 1002945951U, 3181438866U, 22506664U, 691783457U, 2685221343U,
  171579916U, 3878728600U, 2475806724U, 2030324028U, 3331164912U, 1708711359U,
  1970023127U, 2859691344U, 2588476477U, 2748146879U, 136111222U, 2967685492U,
  909517429U, 2835297809U, 3206906216U, 3186870716U, 341264097U, 2542035121U,
  3353277068U, 548223577U, 3170936588U, 1678403446U, 297435620U, 2337555430U,
  466603495U, 1132321815U, 1208589219U, 696392160U, 894244439U, 2562678859U,
  470224582U, 3306867480U, 201364898U, 2075966438U, 1767227936U, 2929737987U,
  3674877796U, 2654196643U, 3692734598U, 3528895099U, 2796780123U, 3048728353U,
  842329300U, 191554730U, 2922459673U, 3489020079U, 3979110629U, 1022523848U,
  2202932467U, 3583655201U, 3565113719U, 587085778U, 4176046313U, 3013713762U,
  950944241U, 396426791U, 3784844662U, 3477431613U, 3594592395U, 2782043838U,
  3392093507U, 3106564952U, 2829419931U, 1358665591U, 2206918825U, 3170783123U,
  31522386U, 2988194168U, 1782249537U, 1105080928U, 843500134U, 1225290080U,
  1521001832U, 3605886097U, 2802786495U, 2728923319U, 3996284304U, 903417639U,
  1171249804U, 1020374987U, 2824535874U, 423621996U, 1988534473U, 2493544470U,
  1008604435U, 1756003503U, 1488867287U, 1386808992U, 732088248U, 1780630732U,
  2482101014U, 976561178U, 1543448953U, 2602866064U, 2021139923U, 1952599828U,
  2360242564U, 2117959962U, 2753061860U, 2388623612U, 4138193781U, 2962920654U,
  2284970429U, 766920861U, 3457264692U, 2879611383U, 815055854U, 2332929068U,
  1254853997U, 3740375268U, 3799380844U, 4091048725U, 2006331129U, 1982546212U,
  686850534U, 1907447564U, 2682801776U, 2780821066U, 998290361U, 1342433871U,
  4195430425U, 607905174U, 3902331779U, 2454067926U, 1708133115U, 1170874362U,
  2008609376U, 3260320415U, 2211196135U, 433538229U, 2728786374U, 2189520818U,
  262554063U, 1182318347U, 3710237267U, 1221022450U, 715966018U, 2417068910U,
  2591870721U, 2870691989U, 3418190842U, 4238214053U, 1540704231U, 1575580968U,
  2095917976U, 4078310857U, 2313532447U, 2110690783U, 4056346629U, 4061784526U,
  1123218514U, 551538993U, 597148360U, 4120175196U, 3581618160U, 3181170517U,
  422862282U, 3227524138U, 1713114790U, 662317149U, 1230418732U, 928171837U,
  1324564878U, 1928816105U, 1786535431U, 2878099422U, 3290185549U, 539474248U,
  1657512683U, 552370646U, 1671741683U, 3655312128U, 1552739510U, 2605208763U,
  1441755014U, 181878989U, 3124053868U, 1447103986U, 3183906156U, 1728556020U,
  3502241336U, 3055466967U, 1013272474U, 818402132U, 1715099063U, 2900113506U,
  397254517U, 4194863039U, 1009068739U, 232864647U, 2540223708U, 2608288560U,
  2415367765U, 478404847U, 3455100648U, 3182600021U, 2115988978U, 434269567U,
  4117179324U, 3461774077U, 887256537U, 3545801025U, 286388911U, 3451742129U,
  1981164769U, 786667016U, 3310123729U, 3097811076U, 2224235657U, 2959658883U,
  3370969234U, 2514770915U, 3345656436U, 2677010851U, 2206236470U, 271648054U,
  2342188545U, 4292848611U, 3646533909U, 3754009956U, 3803931226U, 4160647125U,
  1477814055U, 4043852216U, 1876372354U, 3133294443U, 3871104810U, 3177020907U,
  2074304428U, 3479393793U, 759562891U, 164128153U, 1839069216U, 2114162633U,
  3989947309U, 3611054956U, 1333547922U, 835429831U, 494987340U, 171987910U,
  1252001001U, 370809172U, 3508925425U, 2535703112U, 1276855041U, 1922855120U,
  835673414U, 3030664304U, 613287117U, 171219893U, 3423096126U, 3376881639U,
  2287770315U, 1658692645U, 1262815245U, 3957234326U, 1168096164U, 2968737525U,
  2655813712U, 2132313144U, 3976047964U, 326516571U, 353088456U, 3679188938U,
  3205649712U, 2654036126U, 1249024881U, 880166166U, 691800469U, 2229503665U,
  1673458056U, 4032208375U, 1851778863U, 2563757330U, 376742205U, 1794655231U,
  340247333U, 1505873033U, 396524441U, 879666767U, 3335579166U, 3260764261U,
  3335999539U, 506221798U, 4214658741U, 975887814U, 2080536343U, 3360539560U,
  571586418U, 138896374U, 4234352651U, 2737620262U, 3928362291U, 1516365296U,
  38056726U, 3599462320U, 3585007266U, 3850961033U, 471667319U, 1536883193U,
  2310166751U, 1861637689U, 2530999841U, 4139843801U, 2710569485U, 827578615U,
  2012334720U, 2907369459U, 3029312804U, 2820112398U, 1965028045U, 35518606U,
  2478379033U, 643747771U, 1924139484U, 4123405127U, 3811735531U, 3429660832U,
  3285177704U, 1948416081U, 1311525291U, 1183517742U, 1739192232U, 3979815115U,
  2567840007U, 4116821529U, 213304419U, 4125718577U, 1473064925U, 2442436592U,
  1893310111U, 4195361916U, 3747569474U, 828465101U, 2991227658U, 750582866U,
  1205170309U, 1409813056U, 678418130U, 1171531016U, 3821236156U, 354504587U,
  4202874632U, 3882511497U, 1893248677U, 1903078632U, 26340130U, 2069166240U,
  3657122492U, 3725758099U, 831344905U, 811453383U, 3447711422U, 2434543565U,
  4166886888U, 3358210805U, 4142984013U, 2988152326U, 3527824853U, 982082992U,
  2809155763U, 190157081U, 3340214818U, 2365432395U, 2548636180U, 2894533366U,
  3474657421U, 2372634704U, 2845748389U, 43024175U, 2774226648U, 1987702864U,
  3186502468U, 453610222U, 4204736567U, 1392892630U, 2471323686U, 2470534280U,
  3541393095U, 4269885866U, 3909911300U, 759132955U, 1482612480U, 667715263U,
  1795580598U, 2337923983U, 3390586366U, 581426223U, 1515718634U, 476374295U,
  705213300U, 363062054U, 2084697697U, 2407503428U, 2292957699U, 2426213835U,
  2199989172U, 1987356470U, 4026755612U, 2147252133U, 270400031U, 1367820199U,
  2369854699U, 2844269403U, 79981964U, 624U };

/* Function Declarations */
static void initialize_c4_RocketSim(SFc4_RocketSimInstanceStruct *chartInstance);
static void initialize_params_c4_RocketSim(SFc4_RocketSimInstanceStruct
  *chartInstance);
static void enable_c4_RocketSim(SFc4_RocketSimInstanceStruct *chartInstance);
static void disable_c4_RocketSim(SFc4_RocketSimInstanceStruct *chartInstance);
static void c4_update_jit_animation_state_c4_RocketSim
  (SFc4_RocketSimInstanceStruct *chartInstance);
static void c4_do_animation_call_c4_RocketSim(SFc4_RocketSimInstanceStruct
  *chartInstance);
static void ext_mode_exec_c4_RocketSim(SFc4_RocketSimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c4_RocketSim(SFc4_RocketSimInstanceStruct
  *chartInstance);
static void set_sim_state_c4_RocketSim(SFc4_RocketSimInstanceStruct
  *chartInstance, const mxArray *c4_st);
static void sf_gateway_c4_RocketSim(SFc4_RocketSimInstanceStruct *chartInstance);
static void mdl_start_c4_RocketSim(SFc4_RocketSimInstanceStruct *chartInstance);
static void mdl_terminate_c4_RocketSim(SFc4_RocketSimInstanceStruct
  *chartInstance);
static void mdl_setup_runtime_resources_c4_RocketSim
  (SFc4_RocketSimInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c4_RocketSim
  (SFc4_RocketSimInstanceStruct *chartInstance);
static void initSimStructsc4_RocketSim(SFc4_RocketSimInstanceStruct
  *chartInstance);
static real_T c4_now(SFc4_RocketSimInstanceStruct *chartInstance);
static real_T c4_mod(SFc4_RocketSimInstanceStruct *chartInstance, real_T c4_x);
static real_T c4_rand(SFc4_RocketSimInstanceStruct *chartInstance, const
                      emlrtStack *c4_sp);
static void c4_eml_rand_mt19937ar(SFc4_RocketSimInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, uint32_T c4_d_state[625], uint32_T c4_e_state[625],
  real_T *c4_r);
static real_T c4_emlrt_marshallIn(SFc4_RocketSimInstanceStruct *chartInstance,
  const mxArray *c4_a__output_of_feval_, const char_T *c4_identifier);
static real_T c4_b_emlrt_marshallIn(SFc4_RocketSimInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static uint32_T c4_c_emlrt_marshallIn(SFc4_RocketSimInstanceStruct
  *chartInstance, const mxArray *c4_b_method, const char_T *c4_identifier,
  boolean_T *c4_svPtr);
static uint32_T c4_d_emlrt_marshallIn(SFc4_RocketSimInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  boolean_T *c4_svPtr);
static void c4_e_emlrt_marshallIn(SFc4_RocketSimInstanceStruct *chartInstance,
  const mxArray *c4_d_state, const char_T *c4_identifier, boolean_T *c4_svPtr,
  uint32_T c4_y[625]);
static void c4_f_emlrt_marshallIn(SFc4_RocketSimInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, boolean_T
  *c4_svPtr, uint32_T c4_y[625]);
static void c4_g_emlrt_marshallIn(SFc4_RocketSimInstanceStruct *chartInstance,
  const mxArray *c4_d_state, const char_T *c4_identifier, boolean_T *c4_svPtr,
  uint32_T c4_y[2]);
static void c4_h_emlrt_marshallIn(SFc4_RocketSimInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, boolean_T
  *c4_svPtr, uint32_T c4_y[2]);
static uint8_T c4_i_emlrt_marshallIn(SFc4_RocketSimInstanceStruct *chartInstance,
  const mxArray *c4_b_is_active_c4_RocketSim, const char_T *c4_identifier);
static uint8_T c4_j_emlrt_marshallIn(SFc4_RocketSimInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_chart_data_browse_helper(SFc4_RocketSimInstanceStruct
  *chartInstance, int32_T c4_ssIdNumber, const mxArray **c4_mxData, uint8_T
  *c4_isValueTooBig);
static const mxArray *c4_feval(SFc4_RocketSimInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1,
  const mxArray *c4_input2, const mxArray *c4_input3);
static const mxArray *c4_b_feval(SFc4_RocketSimInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1,
  const mxArray *c4_input2, const mxArray *c4_input3);
static real_T c4_b_eml_rand_mt19937ar(SFc4_RocketSimInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, uint32_T c4_d_state[625]);
static void init_dsm_address_info(SFc4_RocketSimInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc4_RocketSimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_RocketSim(SFc4_RocketSimInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_seed_not_empty = false;
  chartInstance->c4_method_not_empty = false;
  chartInstance->c4_state_not_empty = false;
  chartInstance->c4_b_state_not_empty = false;
  chartInstance->c4_c_state_not_empty = false;
  chartInstance->c4_is_active_c4_RocketSim = 0U;
}

static void initialize_params_c4_RocketSim(SFc4_RocketSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c4_RocketSim(SFc4_RocketSimInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_RocketSim(SFc4_RocketSimInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c4_update_jit_animation_state_c4_RocketSim
  (SFc4_RocketSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c4_do_animation_call_c4_RocketSim(SFc4_RocketSimInstanceStruct
  *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static void ext_mode_exec_c4_RocketSim(SFc4_RocketSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_RocketSim(SFc4_RocketSimInstanceStruct
  *chartInstance)
{
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_f_y = NULL;
  const mxArray *c4_g_y = NULL;
  const mxArray *c4_h_y = NULL;
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(7, 1), false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", chartInstance->c4_CD_AA, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_c_y = NULL;
  if (!chartInstance->c4_method_not_empty) {
    sf_mex_assign(&c4_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_c_y, sf_mex_create("y", &chartInstance->c4_method, 7, 0U,
      0U, 0U, 0), false);
  }

  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_d_y = NULL;
  if (!chartInstance->c4_method_not_empty) {
    sf_mex_assign(&c4_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_d_y, sf_mex_create("y", &chartInstance->c4_seed, 7, 0U, 0U,
      0U, 0), false);
  }

  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_e_y = NULL;
  if (!chartInstance->c4_method_not_empty) {
    sf_mex_assign(&c4_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_e_y, sf_mex_create("y", &chartInstance->c4_c_state, 7, 0U,
      0U, 0U, 0), false);
  }

  sf_mex_setcell(c4_y, 3, c4_e_y);
  c4_f_y = NULL;
  if (!chartInstance->c4_state_not_empty) {
    sf_mex_assign(&c4_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_f_y, sf_mex_create("y", chartInstance->c4_state, 7, 0U, 1U,
      0U, 1, 625), false);
  }

  sf_mex_setcell(c4_y, 4, c4_f_y);
  c4_g_y = NULL;
  if (!chartInstance->c4_b_state_not_empty) {
    sf_mex_assign(&c4_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_g_y, sf_mex_create("y", chartInstance->c4_b_state, 7, 0U,
      1U, 0U, 1, 2), false);
  }

  sf_mex_setcell(c4_y, 5, c4_g_y);
  c4_h_y = NULL;
  sf_mex_assign(&c4_h_y, sf_mex_create("y",
    &chartInstance->c4_is_active_c4_RocketSim, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 6, c4_h_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_RocketSim(SFc4_RocketSimInstanceStruct
  *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  int32_T c4_i;
  int32_T c4_i1;
  uint32_T c4_b_uv[625];
  uint32_T c4_uv1[2];
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  *chartInstance->c4_CD_AA = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 0)), "CD_AA");
  chartInstance->c4_method = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 1)), "method", &chartInstance->c4_method_not_empty);
  chartInstance->c4_seed = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 2)), "seed", &chartInstance->c4_seed_not_empty);
  chartInstance->c4_c_state = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 3)), "state", &chartInstance->c4_c_state_not_empty);
  c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 4)),
                        "state", &chartInstance->c4_state_not_empty, c4_b_uv);
  for (c4_i = 0; c4_i < 625; c4_i++) {
    chartInstance->c4_state[c4_i] = c4_b_uv[c4_i];
  }

  c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 5)),
                        "state", &chartInstance->c4_b_state_not_empty, c4_uv1);
  for (c4_i1 = 0; c4_i1 < 2; c4_i1++) {
    chartInstance->c4_b_state[c4_i1] = c4_uv1[c4_i1];
  }

  chartInstance->c4_is_active_c4_RocketSim = c4_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 6)), "is_active_c4_RocketSim");
  sf_mex_destroy(&c4_u);
  sf_mex_destroy(&c4_st);
}

static void sf_gateway_c4_RocketSim(SFc4_RocketSimInstanceStruct *chartInstance)
{
  static char_T c4_e_varargin_1[54] = { 'A', 'n', 'g', 'l', 'e', ' ', 'p', 'h',
    'i', ' ', 'o', 'f', ' ', 't', 'h', 'e', ' ', 'a', 'c', 't', 'i', 'v', 'e',
    ' ', 'a', 'e', 'r', 'o', ' ', 'f', 'i', 'n', 's', ' ', 'i', 's', ' ', 'w',
    'r', 'o', 'n', 'g', '.', ' ', 'T', 'o', 'o', ' ', 'S', 'm', 'a', 'l', 'l',
    '.' };

  static char_T c4_d_varargin_1[52] = { 'A', 'n', 'g', 'l', 'e', ' ', 'p', 'h',
    'i', ' ', 'o', 'f', ' ', 't', 'h', 'e', ' ', 'a', 'c', 't', 'i', 'v', 'e',
    ' ', 'a', 'e', 'r', 'o', ' ', 'f', 'i', 'n', 's', ' ', 'i', 's', ' ', 'w',
    'r', 'o', 'n', 'g', '.', ' ', 'T', 'o', 'o', ' ', 'b', 'i', 'g', '.' };

  static char_T c4_cv[22] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'r', 'n', 'g',
    ':', 'b', 'a', 'd', 'S', 'e', 't', 't', 'i', 'n', 'g', 's' };

  static char_T c4_cv1[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  static char_T c4_cv2[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  static char_T c4_cv3[4] = { '%', 's', '\\', 'n' };

  static char_T c4_cv4[4] = { '%', 's', '\\', 'n' };

  time_t c4_b_eTime;
  time_t c4_eTime;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_f_y = NULL;
  const mxArray *c4_g_y = NULL;
  const mxArray *c4_h_y = NULL;
  const mxArray *c4_i_y = NULL;
  const mxArray *c4_j_y = NULL;
  const mxArray *c4_k_y = NULL;
  const mxArray *c4_l_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_b_CD_AA;
  real_T c4_b_fileID;
  real_T c4_b_mti;
  real_T c4_b_phi;
  real_T c4_b_u;
  real_T c4_b_x;
  real_T c4_c_u;
  real_T c4_c_x;
  real_T c4_d;
  real_T c4_d1;
  real_T c4_d_x;
  real_T c4_e_x;
  real_T c4_f_x;
  real_T c4_fileID;
  real_T c4_g_x;
  real_T c4_h_x;
  real_T c4_pert;
  real_T c4_s;
  real_T c4_s0;
  real_T c4_x;
  int32_T c4_exitg1;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_mti;
  int32_T c4_prevEpochTime;
  int32_T c4_t;
  uint32_T c4_arg3;
  uint32_T c4_b_arg3;
  uint32_T c4_b_r;
  uint32_T c4_b_s;
  uint32_T c4_b_seed;
  uint32_T c4_b_t;
  uint32_T c4_b_varargin_1;
  uint32_T c4_c_arg3;
  uint32_T c4_c_seed;
  uint32_T c4_c_varargin_1;
  uint32_T c4_d_state;
  uint32_T c4_method2;
  uint32_T c4_r;
  uint32_T c4_u;
  uint32_T c4_u1;
  uint32_T c4_varargin_1;
  boolean_T c4_covSaturation;
  c4_st.tls = chartInstance->c4_fEmlrtCtx;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  chartInstance->c4_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  covrtSigUpdateFcn(chartInstance->c4_covrtInstance, 0U, *chartInstance->c4_phi);
  chartInstance->c4_sfEvent = CALL_EVENT;
  c4_b_phi = *chartInstance->c4_phi;
  covrtEmlFcnEval(chartInstance->c4_covrtInstance, 4U, 0, 0);
  c4_b_st.site = &c4_emlrtRSI;
  if (!chartInstance->c4_seed_not_empty) {
    chartInstance->c4_seed = 0U;
    chartInstance->c4_seed_not_empty = true;
  }

  c4_c_st.site = &c4_e_emlrtRSI;
  if (!chartInstance->c4_method_not_empty) {
    chartInstance->c4_method = 7U;
    chartInstance->c4_method_not_empty = true;
  }

  c4_c_st.site = &c4_f_emlrtRSI;
  c4_d_st.site = &c4_k_emlrtRSI;
  c4_x = c4_now(chartInstance) * 8.64E+6;
  c4_b_x = c4_x;
  c4_b_x = muDoubleScalarFloor(c4_b_x);
  c4_s = c4_mod(chartInstance, c4_b_x);
  c4_d_st.site = &c4_l_emlrtRSI;
  c4_eTime = time(NULL);
  c4_prevEpochTime = (int32_T)c4_eTime + 1;
  do {
    c4_exitg1 = 0;
    c4_d_st.site = &c4_m_emlrtRSI;
    c4_b_eTime = time(NULL);
    c4_t = (int32_T)c4_b_eTime;
    if (c4_t <= c4_prevEpochTime) {
      c4_d_st.site = &c4_n_emlrtRSI;
      c4_c_x = c4_now(chartInstance) * 8.64E+6;
      c4_d_x = c4_c_x;
      c4_d_x = muDoubleScalarFloor(c4_d_x);
      c4_s0 = c4_mod(chartInstance, c4_d_x);
      if (c4_s != c4_s0) {
        c4_exitg1 = 1;
      }
    } else {
      c4_exitg1 = 1;
    }
  } while (c4_exitg1 == 0);

  c4_d = muDoubleScalarRound(c4_s);
  c4_covSaturation = false;
  if (c4_d < 4.294967296E+9) {
    if (c4_d >= 0.0) {
      c4_u = (uint32_T)c4_d;
    } else {
      c4_covSaturation = true;
      c4_u = 0U;
      sf_data_saturate_error(chartInstance->S, 1U, 271, 14);
    }
  } else if (c4_d >= 4.294967296E+9) {
    c4_covSaturation = true;
    c4_u = MAX_uint32_T;
    sf_data_saturate_error(chartInstance->S, 1U, 271, 14);
  } else {
    c4_u = 0U;
  }

  covrtSaturationUpdateFcn(chartInstance->c4_covrtInstance, 4, 0, 0, 0,
    c4_covSaturation);
  chartInstance->c4_seed = c4_u;
  c4_c_st.site = &c4_g_emlrtRSI;
  if (!chartInstance->c4_method_not_empty) {
    chartInstance->c4_method = 7U;
    chartInstance->c4_method_not_empty = true;
  }

  c4_method2 = chartInstance->c4_method;
  if (c4_method2 == 7U) {
    c4_c_st.site = &c4_h_emlrtRSI;
    c4_varargin_1 = chartInstance->c4_seed;
    if (!chartInstance->c4_state_not_empty) {
      for (c4_i = 0; c4_i < 625; c4_i++) {
        chartInstance->c4_state[c4_i] = c4_uv[c4_i];
      }

      chartInstance->c4_state_not_empty = true;
    }

    c4_d_st.site = &c4_o_emlrtRSI;
    c4_b_arg3 = c4_varargin_1;
    c4_e_st.site = &c4_p_emlrtRSI;
    c4_b_seed = c4_b_arg3;
    c4_r = c4_b_seed;
    chartInstance->c4_state[0] = c4_b_seed;
    for (c4_mti = 0; c4_mti < 623; c4_mti++) {
      c4_b_mti = 2.0 + (real_T)c4_mti;
      c4_d1 = muDoubleScalarRound(c4_b_mti - 1.0);
      if (c4_d1 < 4.294967296E+9) {
        if (c4_d1 >= 0.0) {
          c4_u1 = (uint32_T)c4_d1;
        } else {
          c4_u1 = 0U;
          sf_data_saturate_error(chartInstance->S, 1U, 271, 14);
        }
      } else if (c4_d1 >= 4.294967296E+9) {
        c4_u1 = MAX_uint32_T;
        sf_data_saturate_error(chartInstance->S, 1U, 271, 14);
      } else {
        c4_u1 = 0U;
      }

      c4_r = (c4_r ^ c4_r >> 30U) * 1812433253U + c4_u1;
      chartInstance->c4_state[(int32_T)c4_b_mti - 1] = c4_r;
    }

    chartInstance->c4_state[624] = 624U;
  } else if (c4_method2 == 5U) {
    c4_c_st.site = &c4_i_emlrtRSI;
    c4_b_varargin_1 = chartInstance->c4_seed;
    if (!chartInstance->c4_b_state_not_empty) {
      for (c4_i1 = 0; c4_i1 < 2; c4_i1++) {
        chartInstance->c4_b_state[c4_i1] = 362436069U + 158852560U * (uint32_T)
          c4_i1;
      }

      chartInstance->c4_b_state_not_empty = true;
    }

    c4_arg3 = c4_b_varargin_1;
    c4_b_s = c4_arg3;
    chartInstance->c4_b_state[0] = 362436069U;
    chartInstance->c4_b_state[1] = c4_b_s;
    if ((real_T)chartInstance->c4_b_state[1] == 0.0) {
      chartInstance->c4_b_state[1] = 521288629U;
    }
  } else if (c4_method2 == 4U) {
    c4_c_st.site = &c4_j_emlrtRSI;
    c4_c_varargin_1 = chartInstance->c4_seed;
    if (!chartInstance->c4_c_state_not_empty) {
      chartInstance->c4_c_state = 1144108930U;
      chartInstance->c4_c_state_not_empty = true;
    }

    c4_d_st.site = &c4_q_emlrtRSI;
    c4_c_arg3 = c4_c_varargin_1;
    c4_e_st.site = &c4_r_emlrtRSI;
    c4_c_seed = c4_c_arg3;
    c4_b_r = c4_c_seed >> 16U;
    c4_b_t = c4_c_seed & 32768U;
    c4_d_state = c4_b_r << 16U;
    c4_d_state = c4_c_seed - c4_d_state;
    c4_d_state -= c4_b_t;
    c4_d_state <<= 16U;
    c4_d_state += c4_b_t;
    c4_d_state += c4_b_r;
    if ((real_T)c4_d_state < 1.0) {
      c4_d_state = 1144108930U;
    } else if (c4_d_state > 2147483646U) {
      c4_d_state = 2147483646U;
    }

    chartInstance->c4_c_state = c4_d_state;
  } else {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1, 22),
                  false);
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1, 22),
                  false);
    sf_mex_call(&c4_b_st, &c4_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14,
                sf_mex_call(&c4_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_b_st, NULL, "message", 1U, 1U, 14, c4_b_y)));
  }

  if (covrtEmlIfEval(chartInstance->c4_covrtInstance, 4U, 0, 0,
                     covrtRelationalopUpdateFcn(chartInstance->c4_covrtInstance,
        4U, 0U, 0U, c4_b_phi, 3.1415926535897931, -1, 4U, c4_b_phi >
        3.1415926535897931))) {
    c4_b_st.site = &c4_b_emlrtRSI;
    c4_c_st.site = &c4_s_emlrtRSI;
    c4_d_st.site = &c4_t_emlrtRSI;
    c4_fileID = 1.0;
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_cv1, 10, 0U, 1U, 0U, 2, 1, 7),
                  false);
    c4_e_y = NULL;
    sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_fileID, 0, 0U, 0U, 0U, 0),
                  false);
    c4_g_y = NULL;
    sf_mex_assign(&c4_g_y, sf_mex_create("y", c4_cv3, 10, 0U, 1U, 0U, 2, 1, 4),
                  false);
    c4_i_y = NULL;
    sf_mex_assign(&c4_i_y, sf_mex_create("y", c4_d_varargin_1, 10, 0U, 1U, 0U, 2,
      1, 52), false);
    c4_e_st.site = &c4_u_emlrtRSI;
    c4_emlrt_marshallIn(chartInstance, c4_feval(chartInstance, &c4_e_st, c4_c_y,
      c4_e_y, c4_g_y, c4_i_y), "<output of feval>");
    c4_b_u = c4_b_phi * 180.0 / 3.1415926535897931;
    c4_k_y = NULL;
    sf_mex_assign(&c4_k_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0), false);
    sf_mex_call(&c4_st, NULL, "disp", 0U, 1U, 14, c4_k_y);
    c4_b_CD_AA = 1.28;
  } else if (covrtEmlIfEval(chartInstance->c4_covrtInstance, 4U, 0, 1,
              covrtRelationalopUpdateFcn(chartInstance->c4_covrtInstance, 4U, 0U,
    1U, -c4_b_phi, 3.1415926535897931, -1, 4U, -c4_b_phi > 3.1415926535897931)))
  {
    c4_b_st.site = &c4_c_emlrtRSI;
    c4_c_st.site = &c4_s_emlrtRSI;
    c4_d_st.site = &c4_t_emlrtRSI;
    c4_b_fileID = 1.0;
    c4_d_y = NULL;
    sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_cv2, 10, 0U, 1U, 0U, 2, 1, 7),
                  false);
    c4_f_y = NULL;
    sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_b_fileID, 0, 0U, 0U, 0U, 0),
                  false);
    c4_h_y = NULL;
    sf_mex_assign(&c4_h_y, sf_mex_create("y", c4_cv4, 10, 0U, 1U, 0U, 2, 1, 4),
                  false);
    c4_j_y = NULL;
    sf_mex_assign(&c4_j_y, sf_mex_create("y", c4_e_varargin_1, 10, 0U, 1U, 0U, 2,
      1, 54), false);
    c4_e_st.site = &c4_u_emlrtRSI;
    c4_emlrt_marshallIn(chartInstance, c4_b_feval(chartInstance, &c4_e_st,
      c4_d_y, c4_f_y, c4_h_y, c4_j_y), "<output of feval>");
    c4_c_u = c4_b_phi * 180.0 / 3.1415926535897931;
    c4_l_y = NULL;
    sf_mex_assign(&c4_l_y, sf_mex_create("y", &c4_c_u, 0, 0U, 0U, 0U, 0), false);
    sf_mex_call(&c4_st, NULL, "disp", 0U, 1U, 14, c4_l_y);
    c4_b_CD_AA = 0.045;
  } else {
    if (covrtEmlIfEval(chartInstance->c4_covrtInstance, 4U, 0, 2,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c4_covrtInstance, 4U, 0U, 2U, c4_b_phi,
                        1.5707963267948966, -1, 4U, c4_b_phi >
                        1.5707963267948966))) {
      c4_b_phi = 1.5707963267948966;
    } else if (covrtEmlIfEval(chartInstance->c4_covrtInstance, 4U, 0, 3,
                covrtRelationalopUpdateFcn(chartInstance->c4_covrtInstance, 4U,
                 0U, 3U, c4_b_phi, 0.0, -1, 2U, c4_b_phi < 0.0))) {
      c4_b_phi = 0.0;
    }

    if (covrtEmlIfEval(chartInstance->c4_covrtInstance, 4U, 0, 4,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c4_covrtInstance, 4U, 0U, 4U, c4_b_phi *
                        180.0 / 3.1415926535897931, 16.0, -1, 3U, c4_b_phi *
                        180.0 / 3.1415926535897931 <= 16.0))) {
      c4_e_x = 1.0 + c4_b_phi * 180.0 / 3.1415926535897931 / 16.0;
      c4_f_x = c4_e_x;
      c4_f_x = muDoubleScalarExp(c4_f_x);
      c4_b_CD_AA = 0.045 + 0.44999999999999996 * c4_f_x / 7.38905609893065;
    } else {
      c4_b_CD_AA = 0.495 + (c4_b_phi * 180.0 / 3.1415926535897931 - 16.0) / 74.0
        * 0.785;
      c4_b_st.site = &c4_d_emlrtRSI;
      c4_pert = c4_rand(chartInstance, &c4_b_st);
      c4_g_x = c4_pert - 0.5;
      c4_h_x = c4_g_x;
      c4_h_x = muDoubleScalarSign(c4_h_x);
      c4_b_CD_AA += c4_h_x * c4_b_CD_AA / 20.0 * c4_pert;
    }
  }

  *chartInstance->c4_CD_AA = c4_b_CD_AA;
  c4_do_animation_call_c4_RocketSim(chartInstance);
  covrtSigUpdateFcn(chartInstance->c4_covrtInstance, 1U,
                    *chartInstance->c4_CD_AA);
}

static void mdl_start_c4_RocketSim(SFc4_RocketSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_terminate_c4_RocketSim(SFc4_RocketSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c4_RocketSim
  (SFc4_RocketSimInstanceStruct *chartInstance)
{
  static const uint32_T c4_decisionTxtEndIdx = 0U;
  static const uint32_T c4_decisionTxtStartIdx = 0U;
  setLegacyDebuggerFlag(chartInstance->S, false);
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c4_chart_data_browse_helper);
  chartInstance->c4_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c4_RuntimeVar,
    &chartInstance->c4_IsDebuggerActive,
    &chartInstance->c4_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c4_mlFcnLineNumber, &chartInstance->c4_IsHeatMapPresent, 0);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c4_covrtInstance, 1U, 0U, 1U,
    28U);
  covrtChartInitFcn(chartInstance->c4_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c4_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c4_decisionTxtStartIdx, &c4_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c4_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c4_covrtInstance, "", 4U, 0U, 1U, 0U, 5U, 0U,
                  1U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 1164);
  covrtEmlSaturationInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U, 271, -1,
    285);
  covrtEmlIfInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U, 304, 316, 435,
                    574);
  covrtEmlIfInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 1U, 435, 452, 574,
                    639);
  covrtEmlIfInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 2U, 574, 590, 607,
                    639);
  covrtEmlIfInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 3U, 607, 622, -1,
                    636);
  covrtEmlIfInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 4U, 766, 792, 889,
                    1162);
  covrtEmlRelationalInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U, 307,
    315, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 1U, 442,
    451, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 2U, 581,
    589, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 3U, 614,
    621, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 4U, 769,
    791, -1, 3U);
}

static void mdl_cleanup_runtime_resources_c4_RocketSim
  (SFc4_RocketSimInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c4_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c4_covrtInstance);
}

static void initSimStructsc4_RocketSim(SFc4_RocketSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

const mxArray *sf_c4_RocketSim_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static real_T c4_now(SFc4_RocketSimInstanceStruct *chartInstance)
{
  time_t c4_rawtime;
  c4_sxaDueAh1f53T9ESYg9Uc4E c4_timeinfoDouble;
  struct tm c4_timeinfo;
  real_T c4_cDaysMonthWise[12];
  real_T c4_a;
  real_T c4_b_a;
  real_T c4_b_r;
  real_T c4_b_x;
  real_T c4_c_a;
  real_T c4_c_r;
  real_T c4_c_x;
  real_T c4_dDateNum;
  real_T c4_d_x;
  real_T c4_e_x;
  real_T c4_f_x;
  real_T c4_g_x;
  real_T c4_h_x;
  real_T c4_i_x;
  real_T c4_j_x;
  real_T c4_k_x;
  real_T c4_l_x;
  real_T c4_m_x;
  real_T c4_n_x;
  real_T c4_o_x;
  real_T c4_p_x;
  real_T c4_q_x;
  real_T c4_r;
  real_T c4_r_x;
  real_T c4_s_x;
  real_T c4_t_x;
  real_T c4_u_x;
  real_T c4_x;
  boolean_T c4_b;
  boolean_T c4_b_b;
  boolean_T c4_b_rEQ0;
  boolean_T c4_c_b;
  boolean_T c4_c_rEQ0;
  boolean_T c4_d_b;
  boolean_T c4_e_b;
  boolean_T c4_f_b;
  boolean_T c4_guard1 = false;
  boolean_T c4_rEQ0;
  (void)chartInstance;
  c4_cDaysMonthWise[0] = 0.0;
  c4_cDaysMonthWise[1] = 31.0;
  c4_cDaysMonthWise[2] = 59.0;
  c4_cDaysMonthWise[3] = 90.0;
  c4_cDaysMonthWise[4] = 120.0;
  c4_cDaysMonthWise[5] = 151.0;
  c4_cDaysMonthWise[6] = 181.0;
  c4_cDaysMonthWise[7] = 212.0;
  c4_cDaysMonthWise[8] = 243.0;
  c4_cDaysMonthWise[9] = 273.0;
  c4_cDaysMonthWise[10] = 304.0;
  c4_cDaysMonthWise[11] = 334.0;
  time(&c4_rawtime);
  c4_timeinfo = *localtime(&c4_rawtime);
  c4_timeinfo.tm_year += 1900;
  c4_timeinfo.tm_mon++;
  c4_timeinfoDouble.tm_min = (real_T)c4_timeinfo.tm_min;
  c4_timeinfoDouble.tm_sec = (real_T)c4_timeinfo.tm_sec;
  c4_timeinfoDouble.tm_hour = (real_T)c4_timeinfo.tm_hour;
  c4_timeinfoDouble.tm_mday = (real_T)c4_timeinfo.tm_mday;
  c4_timeinfoDouble.tm_mon = (real_T)c4_timeinfo.tm_mon;
  c4_timeinfoDouble.tm_year = (real_T)c4_timeinfo.tm_year;
  c4_x = c4_timeinfoDouble.tm_year / 4.0;
  c4_b_x = c4_x;
  c4_b_x = muDoubleScalarCeil(c4_b_x);
  c4_c_x = c4_timeinfoDouble.tm_year / 100.0;
  c4_d_x = c4_c_x;
  c4_d_x = muDoubleScalarCeil(c4_d_x);
  c4_e_x = c4_timeinfoDouble.tm_year / 400.0;
  c4_f_x = c4_e_x;
  c4_f_x = muDoubleScalarCeil(c4_f_x);
  c4_dDateNum = ((((365.0 * c4_timeinfoDouble.tm_year + c4_b_x) - c4_d_x) +
                  c4_f_x) + c4_cDaysMonthWise[(int32_T)c4_timeinfoDouble.tm_mon
                 - 1]) + c4_timeinfoDouble.tm_mday;
  if (c4_timeinfoDouble.tm_mon > 2.0) {
    c4_g_x = c4_timeinfoDouble.tm_year;
    c4_a = c4_g_x;
    c4_h_x = c4_a;
    c4_i_x = c4_h_x;
    c4_j_x = c4_i_x;
    c4_b = muDoubleScalarIsNaN(c4_j_x);
    if (c4_b) {
      c4_r = rtNaN;
    } else {
      c4_k_x = c4_i_x;
      c4_b_b = muDoubleScalarIsInf(c4_k_x);
      if (c4_b_b) {
        c4_r = rtNaN;
      } else if (c4_i_x == 0.0) {
        c4_r = 0.0;
      } else {
        c4_r = muDoubleScalarRem(c4_i_x, 4.0);
        c4_rEQ0 = (c4_r == 0.0);
        if (c4_rEQ0) {
          c4_r = 0.0;
        } else if (c4_i_x < 0.0) {
          c4_r += 4.0;
        }
      }
    }

    c4_guard1 = false;
    if (c4_r == 0.0) {
      c4_l_x = c4_timeinfoDouble.tm_year;
      c4_b_a = c4_l_x;
      c4_m_x = c4_b_a;
      c4_o_x = c4_m_x;
      c4_p_x = c4_o_x;
      c4_c_b = muDoubleScalarIsNaN(c4_p_x);
      if (c4_c_b) {
        c4_b_r = rtNaN;
      } else {
        c4_t_x = c4_o_x;
        c4_e_b = muDoubleScalarIsInf(c4_t_x);
        if (c4_e_b) {
          c4_b_r = rtNaN;
        } else if (c4_o_x == 0.0) {
          c4_b_r = 0.0;
        } else {
          c4_b_r = muDoubleScalarRem(c4_o_x, 100.0);
          c4_b_rEQ0 = (c4_b_r == 0.0);
          if (c4_b_rEQ0) {
            c4_b_r = 0.0;
          } else if (c4_o_x < 0.0) {
            c4_b_r += 100.0;
          }
        }
      }

      if (c4_b_r != 0.0) {
        c4_dDateNum++;
      } else {
        c4_guard1 = true;
      }
    } else {
      c4_guard1 = true;
    }

    if (c4_guard1) {
      c4_n_x = c4_timeinfoDouble.tm_year;
      c4_c_a = c4_n_x;
      c4_q_x = c4_c_a;
      c4_r_x = c4_q_x;
      c4_s_x = c4_r_x;
      c4_d_b = muDoubleScalarIsNaN(c4_s_x);
      if (c4_d_b) {
        c4_c_r = rtNaN;
      } else {
        c4_u_x = c4_r_x;
        c4_f_b = muDoubleScalarIsInf(c4_u_x);
        if (c4_f_b) {
          c4_c_r = rtNaN;
        } else if (c4_r_x == 0.0) {
          c4_c_r = 0.0;
        } else {
          c4_c_r = muDoubleScalarRem(c4_r_x, 400.0);
          c4_c_rEQ0 = (c4_c_r == 0.0);
          if (c4_c_rEQ0) {
            c4_c_r = 0.0;
          } else if (c4_r_x < 0.0) {
            c4_c_r += 400.0;
          }
        }
      }

      if (c4_c_r == 0.0) {
        c4_dDateNum++;
      }
    }
  }

  c4_dDateNum += ((c4_timeinfoDouble.tm_hour * 3600.0 + c4_timeinfoDouble.tm_min
                   * 60.0) + c4_timeinfoDouble.tm_sec) / 86400.0;
  return c4_dDateNum;
}

static real_T c4_mod(SFc4_RocketSimInstanceStruct *chartInstance, real_T c4_x)
{
  real_T c4_a;
  real_T c4_b_x;
  real_T c4_c_x;
  real_T c4_d_x;
  real_T c4_e_x;
  real_T c4_r;
  boolean_T c4_b;
  boolean_T c4_b_b;
  boolean_T c4_rEQ0;
  (void)chartInstance;
  c4_a = c4_x;
  c4_b_x = c4_a;
  c4_c_x = c4_b_x;
  c4_d_x = c4_c_x;
  c4_b = muDoubleScalarIsNaN(c4_d_x);
  if (c4_b) {
    c4_r = rtNaN;
  } else {
    c4_e_x = c4_c_x;
    c4_b_b = muDoubleScalarIsInf(c4_e_x);
    if (c4_b_b) {
      c4_r = rtNaN;
    } else if (c4_c_x == 0.0) {
      c4_r = 0.0;
    } else {
      c4_r = muDoubleScalarRem(c4_c_x, 2.147483647E+9);
      c4_rEQ0 = (c4_r == 0.0);
      if (c4_rEQ0) {
        c4_r = 0.0;
      } else if (c4_c_x < 0.0) {
        c4_r += 2.147483647E+9;
      }
    }
  }

  return c4_r;
}

static real_T c4_rand(SFc4_RocketSimInstanceStruct *chartInstance, const
                      emlrtStack *c4_sp)
{
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_st;
  real_T c4_b_r;
  real_T c4_c_r;
  real_T c4_d;
  real_T c4_d1;
  real_T c4_d2;
  real_T c4_r;
  int32_T c4_i;
  int32_T c4_i1;
  uint32_T c4_a;
  uint32_T c4_b;
  uint32_T c4_d_state;
  uint32_T c4_e_state;
  uint32_T c4_f_state;
  uint32_T c4_hi;
  uint32_T c4_icng;
  uint32_T c4_jsr;
  uint32_T c4_lo;
  uint32_T c4_s;
  uint32_T c4_test1;
  uint32_T c4_test2;
  uint32_T c4_u;
  uint32_T c4_u1;
  uint32_T c4_ui;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_v_emlrtRSI;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  if (!chartInstance->c4_method_not_empty) {
    chartInstance->c4_method = 7U;
    chartInstance->c4_method_not_empty = true;
  }

  if (chartInstance->c4_method == 4U) {
    c4_b_st.site = &c4_w_emlrtRSI;
    if (!chartInstance->c4_c_state_not_empty) {
      chartInstance->c4_c_state = 1144108930U;
      chartInstance->c4_c_state_not_empty = true;
    }

    c4_d_state = chartInstance->c4_c_state;
    c4_e_state = c4_d_state;
    c4_s = c4_e_state;
    c4_hi = c4_s / 127773U;
    c4_lo = c4_s - c4_hi * 127773U;
    c4_test1 = 16807U * c4_lo;
    c4_test2 = 2836U * c4_hi;
    c4_a = c4_test1;
    c4_b = c4_test2;
    if (c4_a < c4_b) {
      c4_f_state = c4_b - c4_a;
      c4_f_state = ~c4_f_state;
      c4_f_state &= 2147483647U;
    } else {
      c4_f_state = c4_a - c4_b;
    }

    c4_c_r = (real_T)c4_f_state * 4.6566128752457969E-10;
    c4_e_state = c4_f_state;
    c4_d2 = c4_c_r;
    chartInstance->c4_c_state = c4_e_state;
    c4_r = c4_d2;
  } else if (chartInstance->c4_method == 5U) {
    c4_b_st.site = &c4_x_emlrtRSI;
    if (!chartInstance->c4_b_state_not_empty) {
      for (c4_i1 = 0; c4_i1 < 2; c4_i1++) {
        chartInstance->c4_b_state[c4_i1] = 362436069U + 158852560U * (uint32_T)
          c4_i1;
      }

      chartInstance->c4_b_state_not_empty = true;
    }

    c4_icng = chartInstance->c4_b_state[0];
    c4_jsr = chartInstance->c4_b_state[1];
    c4_u = c4_jsr;
    c4_u1 = c4_icng;
    c4_u1 = 69069U * c4_u1 + 1234567U;
    c4_u ^= c4_u << 13;
    c4_u ^= c4_u >> 17;
    c4_u ^= c4_u << 5;
    c4_ui = c4_u1 + c4_u;
    chartInstance->c4_b_state[0] = c4_u1;
    chartInstance->c4_b_state[1] = c4_u;
    c4_b_r = (real_T)c4_ui * 2.328306436538696E-10;
    c4_d1 = c4_b_r;
    c4_r = c4_d1;
  } else {
    c4_b_st.site = &c4_y_emlrtRSI;
    if (!chartInstance->c4_state_not_empty) {
      for (c4_i = 0; c4_i < 625; c4_i++) {
        chartInstance->c4_state[c4_i] = c4_uv[c4_i];
      }

      chartInstance->c4_state_not_empty = true;
    }

    c4_c_st.site = &c4_db_emlrtRSI;
    c4_d = c4_b_eml_rand_mt19937ar(chartInstance, &c4_c_st,
      chartInstance->c4_state);
    c4_r = c4_d;
  }

  return c4_r;
}

static void c4_eml_rand_mt19937ar(SFc4_RocketSimInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, uint32_T c4_d_state[625], uint32_T c4_e_state[625],
  real_T *c4_r)
{
  int32_T c4_i;
  for (c4_i = 0; c4_i < 625; c4_i++) {
    c4_e_state[c4_i] = c4_d_state[c4_i];
  }

  *c4_r = c4_b_eml_rand_mt19937ar(chartInstance, c4_sp, c4_e_state);
}

static real_T c4_emlrt_marshallIn(SFc4_RocketSimInstanceStruct *chartInstance,
  const mxArray *c4_a__output_of_feval_, const char_T *c4_identifier)
{
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  c4_thisId.fIdentifier = (const char_T *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_a__output_of_feval_),
    &c4_thisId);
  sf_mex_destroy(&c4_a__output_of_feval_);
  return c4_y;
}

static real_T c4_b_emlrt_marshallIn(SFc4_RocketSimInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_d;
  real_T c4_y;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static uint32_T c4_c_emlrt_marshallIn(SFc4_RocketSimInstanceStruct
  *chartInstance, const mxArray *c4_b_method, const char_T *c4_identifier,
  boolean_T *c4_svPtr)
{
  emlrtMsgIdentifier c4_thisId;
  uint32_T c4_y;
  c4_thisId.fIdentifier = (const char_T *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_method),
    &c4_thisId, c4_svPtr);
  sf_mex_destroy(&c4_b_method);
  return c4_y;
}

static uint32_T c4_d_emlrt_marshallIn(SFc4_RocketSimInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  boolean_T *c4_svPtr)
{
  uint32_T c4_b_u;
  uint32_T c4_y;
  (void)chartInstance;
  if (mxIsEmpty(c4_u)) {
    *c4_svPtr = false;
  } else {
    *c4_svPtr = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_b_u, 1, 7, 0U, 0, 0U, 0);
    c4_y = c4_b_u;
  }

  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_e_emlrt_marshallIn(SFc4_RocketSimInstanceStruct *chartInstance,
  const mxArray *c4_d_state, const char_T *c4_identifier, boolean_T *c4_svPtr,
  uint32_T c4_y[625])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char_T *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_d_state), &c4_thisId,
                        c4_svPtr, c4_y);
  sf_mex_destroy(&c4_d_state);
}

static void c4_f_emlrt_marshallIn(SFc4_RocketSimInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, boolean_T
  *c4_svPtr, uint32_T c4_y[625])
{
  int32_T c4_i;
  uint32_T c4_b_uv[625];
  (void)chartInstance;
  if (mxIsEmpty(c4_u)) {
    *c4_svPtr = false;
  } else {
    *c4_svPtr = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_b_uv, 1, 7, 0U, 1, 0U, 1,
                  625);
    for (c4_i = 0; c4_i < 625; c4_i++) {
      c4_y[c4_i] = c4_b_uv[c4_i];
    }
  }

  sf_mex_destroy(&c4_u);
}

static void c4_g_emlrt_marshallIn(SFc4_RocketSimInstanceStruct *chartInstance,
  const mxArray *c4_d_state, const char_T *c4_identifier, boolean_T *c4_svPtr,
  uint32_T c4_y[2])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char_T *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_d_state), &c4_thisId,
                        c4_svPtr, c4_y);
  sf_mex_destroy(&c4_d_state);
}

static void c4_h_emlrt_marshallIn(SFc4_RocketSimInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, boolean_T
  *c4_svPtr, uint32_T c4_y[2])
{
  int32_T c4_i;
  uint32_T c4_b_uv[2];
  (void)chartInstance;
  if (mxIsEmpty(c4_u)) {
    *c4_svPtr = false;
  } else {
    *c4_svPtr = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_b_uv, 1, 7, 0U, 1, 0U, 1, 2);
    for (c4_i = 0; c4_i < 2; c4_i++) {
      c4_y[c4_i] = c4_b_uv[c4_i];
    }
  }

  sf_mex_destroy(&c4_u);
}

static uint8_T c4_i_emlrt_marshallIn(SFc4_RocketSimInstanceStruct *chartInstance,
  const mxArray *c4_b_is_active_c4_RocketSim, const char_T *c4_identifier)
{
  emlrtMsgIdentifier c4_thisId;
  uint8_T c4_y;
  c4_thisId.fIdentifier = (const char_T *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_RocketSim), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_RocketSim);
  return c4_y;
}

static uint8_T c4_j_emlrt_marshallIn(SFc4_RocketSimInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_b_u;
  uint8_T c4_y;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_b_u, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_b_u;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_chart_data_browse_helper(SFc4_RocketSimInstanceStruct
  *chartInstance, int32_T c4_ssIdNumber, const mxArray **c4_mxData, uint8_T
  *c4_isValueTooBig)
{
  real_T c4_d;
  real_T c4_d1;
  *c4_mxData = NULL;
  *c4_mxData = NULL;
  *c4_isValueTooBig = 0U;
  switch (c4_ssIdNumber) {
   case 4U:
    c4_d = *chartInstance->c4_phi;
    sf_mex_assign(c4_mxData, sf_mex_create("mxData", &c4_d, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 5U:
    c4_d1 = *chartInstance->c4_CD_AA;
    sf_mex_assign(c4_mxData, sf_mex_create("mxData", &c4_d1, 0, 0U, 0U, 0U, 0),
                  false);
    break;
  }
}

static const mxArray *c4_feval(SFc4_RocketSimInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1,
  const mxArray *c4_input2, const mxArray *c4_input3)
{
  const mxArray *c4_ = NULL;
  (void)chartInstance;
  c4_ = NULL;
  sf_mex_assign(&c4_, sf_mex_call(c4_sp, NULL, "feval", 1U, 4U, 14, sf_mex_dup
    (c4_input0), 14, sf_mex_dup(c4_input1), 14, sf_mex_dup(c4_input2), 14,
    sf_mex_dup(c4_input3)), false);
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
  sf_mex_destroy(&c4_input2);
  sf_mex_destroy(&c4_input3);
  return c4_;
}

static const mxArray *c4_b_feval(SFc4_RocketSimInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1,
  const mxArray *c4_input2, const mxArray *c4_input3)
{
  const mxArray *c4_ = NULL;
  (void)chartInstance;
  c4_ = NULL;
  sf_mex_assign(&c4_, sf_mex_call(c4_sp, NULL, "feval", 1U, 4U, 14, sf_mex_dup
    (c4_input0), 14, sf_mex_dup(c4_input1), 14, sf_mex_dup(c4_input2), 14,
    sf_mex_dup(c4_input3)), false);
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
  sf_mex_destroy(&c4_input2);
  sf_mex_destroy(&c4_input3);
  return c4_;
}

static real_T c4_b_eml_rand_mt19937ar(SFc4_RocketSimInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, uint32_T c4_d_state[625])
{
  static char_T c4_cv[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  emlrtStack c4_st;
  const mxArray *c4_h_y = NULL;
  const mxArray *c4_i_y = NULL;
  real_T c4_b_j;
  real_T c4_b_r;
  real_T c4_c_kk;
  int32_T c4_a;
  int32_T c4_b_kk;
  int32_T c4_exitg1;
  int32_T c4_i;
  int32_T c4_j;
  int32_T c4_k;
  int32_T c4_kk;
  uint32_T c4_mt[625];
  uint32_T c4_u[2];
  uint32_T c4_b_y;
  uint32_T c4_c_y;
  uint32_T c4_d_y;
  uint32_T c4_e_y;
  uint32_T c4_f_y;
  uint32_T c4_g_y;
  uint32_T c4_mti;
  uint32_T c4_y;
  boolean_T c4_b_isvalid;
  boolean_T c4_exitg2;
  boolean_T c4_isvalid;
  (void)chartInstance;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_eb_emlrtRSI;

  /* ========================= COPYRIGHT NOTICE ============================ */
  /*  This is a uniform (0,1) pseudorandom number generator based on:        */
  /*                                                                         */
  /*  A C-program for MT19937, with initialization improved 2002/1/26.       */
  /*  Coded by Takuji Nishimura and Makoto Matsumoto.                        */
  /*                                                                         */
  /*  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,      */
  /*  All rights reserved.                                                   */
  /*                                                                         */
  /*  Redistribution and use in source and binary forms, with or without     */
  /*  modification, are permitted provided that the following conditions     */
  /*  are met:                                                               */
  /*                                                                         */
  /*    1. Redistributions of source code must retain the above copyright    */
  /*       notice, this list of conditions and the following disclaimer.     */
  /*                                                                         */
  /*    2. Redistributions in binary form must reproduce the above copyright */
  /*       notice, this list of conditions and the following disclaimer      */
  /*       in the documentation and/or other materials provided with the     */
  /*       distribution.                                                     */
  /*                                                                         */
  /*    3. The names of its contributors may not be used to endorse or       */
  /*       promote products derived from this software without specific      */
  /*       prior written permission.                                         */
  /*                                                                         */
  /*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    */
  /*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      */
  /*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  */
  /*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT  */
  /*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  */
  /*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT       */
  /*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  */
  /*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  */
  /*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT    */
  /*  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE */
  /*  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
  /*                                                                         */
  /* =============================   END   ================================= */
  do {
    c4_exitg1 = 0;
    for (c4_j = 0; c4_j < 2; c4_j++) {
      c4_b_j = 1.0 + (real_T)c4_j;
      c4_mti = c4_d_state[624] + 1U;
      if ((real_T)c4_mti >= 625.0) {
        for (c4_kk = 0; c4_kk < 227; c4_kk++) {
          c4_c_kk = 1.0 + (real_T)c4_kk;
          c4_y = (c4_d_state[(int32_T)c4_c_kk - 1] & 2147483648U) | (c4_d_state
            [(int32_T)(c4_c_kk + 1.0) - 1] & 2147483647U);
          c4_b_y = c4_y;
          c4_d_y = c4_b_y;
          if ((c4_d_y & 1U) == 0U) {
            c4_d_y >>= 1U;
          } else {
            c4_d_y = c4_d_y >> 1U ^ 2567483615U;
          }

          c4_d_state[(int32_T)c4_c_kk - 1] = c4_d_state[(int32_T)(c4_c_kk +
            397.0) - 1] ^ c4_d_y;
        }

        for (c4_b_kk = 0; c4_b_kk < 396; c4_b_kk++) {
          c4_c_kk = 228.0 + (real_T)c4_b_kk;
          c4_y = (c4_d_state[(int32_T)c4_c_kk - 1] & 2147483648U) | (c4_d_state
            [(int32_T)(c4_c_kk + 1.0) - 1] & 2147483647U);
          c4_f_y = c4_y;
          c4_g_y = c4_f_y;
          if ((c4_g_y & 1U) == 0U) {
            c4_g_y >>= 1U;
          } else {
            c4_g_y = c4_g_y >> 1U ^ 2567483615U;
          }

          c4_d_state[(int32_T)c4_c_kk - 1] = c4_d_state[(int32_T)((c4_c_kk + 1.0)
            - 228.0) - 1] ^ c4_g_y;
        }

        c4_y = (c4_d_state[623] & 2147483648U) | (c4_d_state[0] & 2147483647U);
        c4_c_y = c4_y;
        c4_e_y = c4_c_y;
        if ((c4_e_y & 1U) == 0U) {
          c4_e_y >>= 1U;
        } else {
          c4_e_y = c4_e_y >> 1U ^ 2567483615U;
        }

        c4_d_state[623] = c4_d_state[396] ^ c4_e_y;
        c4_mti = 1U;
      }

      c4_y = c4_d_state[(int32_T)c4_mti - 1];
      c4_d_state[624] = c4_mti;
      c4_y ^= c4_y >> 11U;
      c4_y ^= c4_y << 7U & 2636928640U;
      c4_y ^= c4_y << 15U & 4022730752U;
      c4_y ^= c4_y >> 18U;
      c4_u[(int32_T)c4_b_j - 1] = c4_y;
    }

    c4_u[0] >>= 5U;
    c4_u[1] >>= 6U;
    c4_b_r = 1.1102230246251565E-16 * ((real_T)c4_u[0] * 6.7108864E+7 + (real_T)
      c4_u[1]);
    if (c4_b_r == 0.0) {
      for (c4_i = 0; c4_i < 625; c4_i++) {
        c4_mt[c4_i] = c4_d_state[c4_i];
      }

      if (((real_T)c4_mt[624] >= 1.0) && ((real_T)c4_mt[624] < 625.0)) {
        c4_isvalid = true;
      } else {
        c4_isvalid = false;
      }

      c4_b_isvalid = c4_isvalid;
      if (c4_isvalid) {
        c4_b_isvalid = false;
        c4_k = 0;
        c4_exitg2 = false;
        while ((!c4_exitg2) && (c4_k + 1 < 625)) {
          if ((real_T)c4_mt[c4_k] == 0.0) {
            c4_a = c4_k + 1;
            c4_k = c4_a;
          } else {
            c4_b_isvalid = true;
            c4_exitg2 = true;
          }
        }
      }

      if (!c4_b_isvalid) {
        c4_h_y = NULL;
        sf_mex_assign(&c4_h_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1,
          37), false);
        c4_i_y = NULL;
        sf_mex_assign(&c4_i_y, sf_mex_create("y", c4_cv, 10, 0U, 1U, 0U, 2, 1,
          37), false);
        sf_mex_call(&c4_st, &c4_b_emlrtMCI, "error", 0U, 2U, 14, c4_h_y, 14,
                    sf_mex_call(&c4_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c4_st, NULL, "message", 1U, 1U, 14, c4_i_y)));
      }
    } else {
      c4_exitg1 = 1;
    }
  } while (c4_exitg1 == 0);

  return c4_b_r;
}

static void init_dsm_address_info(SFc4_RocketSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc4_RocketSimInstanceStruct *chartInstance)
{
  chartInstance->c4_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c4_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c4_phi = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c4_CD_AA = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c4_RocketSim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(768095981U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1906515180U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3643893271U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1826508037U);
}

mxArray *sf_c4_RocketSim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_RocketSim_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("time");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c4_RocketSim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c4_RocketSim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNrtls1Kw0AQxzclrQoiPYjnPkHph9jqxcSKtGChVA8eFuIm2abBbFKSbam3Hj326NGjj+HjePT"
    "o0XxsbV2DARutQheGYSbMZOefH0OA0GoD/+z49rgNQM73m75lQHSyLBZ822A+yovv+YJv9HaAg7"
    "znai3d9zYiYYyG45bdc8L+dTDvn4vpLyz032L56LwcL1e/K/H1Ykx9dqE+z+LGqSLLTJ+ZTt+/R"
    "15arv7z++PmyHFzBDHBtO/oUX1H+Po7C9x3ziz0tYAJBuweUsIcGW6O/GyIq4kU+ruJlAYXkwQ9"
    "OpweQdw4gh3XMVxECmemhT3Yli/P5RPYrZQqZQSp41iqM4aYWNAyVUgQtZAKXWTrvaENB645QhQ"
    "Hj5UgVyR/gYtSgg7iBx1E4GGsB3XNVfPwPI14eJ2mwsM4QYcGx0NjaR5c2yiSf7Mf4vacR32eWX"
    "1/1Tw86BEPEk6Fh/sEPVRODzX1/aAQzSgf1Es1JdS5N7QYLmte0uDlifFy/Tu8aJwe2g/wQsuHh"
    "9Uacnlg1rys90sML17frWqObaS8Xwqp8NJM0GeP0yeITU9BGjVHWNH2la6j3WB6YZL5f/gblyD5"
    "fw=="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_RocketSim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sZm8bK0iiZ6dS3EhTGbtAjH";
}

static void sf_opaque_initialize_c4_RocketSim(void *chartInstanceVar)
{
  initialize_params_c4_RocketSim((SFc4_RocketSimInstanceStruct*)
    chartInstanceVar);
  initialize_c4_RocketSim((SFc4_RocketSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_RocketSim(void *chartInstanceVar)
{
  enable_c4_RocketSim((SFc4_RocketSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_RocketSim(void *chartInstanceVar)
{
  disable_c4_RocketSim((SFc4_RocketSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_RocketSim(void *chartInstanceVar)
{
  sf_gateway_c4_RocketSim((SFc4_RocketSimInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_RocketSim(SimStruct* S)
{
  return get_sim_state_c4_RocketSim((SFc4_RocketSimInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_RocketSim(SimStruct* S, const mxArray *st)
{
  set_sim_state_c4_RocketSim((SFc4_RocketSimInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c4_RocketSim(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_RocketSimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_RocketSim_optimization_info();
    }

    mdl_cleanup_runtime_resources_c4_RocketSim((SFc4_RocketSimInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c4_RocketSim(void *chartInstanceVar)
{
  mdl_start_c4_RocketSim((SFc4_RocketSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_mdl_terminate_c4_RocketSim(void *chartInstanceVar)
{
  mdl_terminate_c4_RocketSim((SFc4_RocketSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_RocketSim((SFc4_RocketSimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_RocketSim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_RocketSim((SFc4_RocketSimInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSimStructsc4_RocketSim((SFc4_RocketSimInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c4_RocketSim_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [23] = {
    "eNrtWDFv20YUpgTHbYAk8FCkaBGg3trJsOMicTq0kimpESrVgiWnQaBCOZFP4kXHO/buKNubxy4",
    "FMnbo0K3d+hf6A7p060/I2LFj31G0LVOkFEeK47QWQNNHfu/de9/77h1JK1etW/i7hceLO5a1jO",
    "d38chbo9+1eJwbO0bXl6yP4/EPaMRDv0Ek8ZU19ceJD7ugBAs1FbzKeyIVRnkPJHAHsYGQOsubo",
    "n7IKB9UQu4Yf+objzpe0xMhc7fRlrg7nB2ityDUDfRTohIcXQFwtSdF2PcqjPRPIpZ63/bAGajQ",
    "n5aCAt0MAxOWqodM04BB+QCcKleaYMTqNLamJhpsfZCZpslUNY+Bwg8YJTw1W4+oJgRIsIa9wMW",
    "/O6HGpJIwxyNSb4NHhqBqdBD5FBySPqnCG13KiRaSElb2mW0MJ2NrMIynLlxgUwjB2LYlkEEgKN",
    "fZ9W9WMNMyJ10GJeiG/WxvTfguNMV/RGEfZCZvPVsMQZI+7PDMSSNCygdRtU5UMgnT1IdHRBYdr",
    "J8CN1O9qBzVJFgnaKFFFgyiJKuqJekQ6c30FvpVo8xZSyb0R8VWs2CRt/IQplXhxFvF4TZhTGXC",
    "WiKowRBY5LVENJkOG3lNxylF3ZZAgo28s1dDyCkWPobZgrs0tVzDBCDqO19jYzmLdEKlhW+jeEu",
    "12uTtSViVa5A94kBaF5CEKkDOInqzvblUmdojEKPSUXhp4JFCZqEs1Qt5aV/IAXIypYmcpmAqmg",
    "n0VR9riSthT+GimQYztZyFc4jjgWsaDGVQx2WD2BROlGltRVx3Q6oPS6AcSYOUqoa46rANlY2gD",
    "gPY4wMu9nlFCr8Z9/gRvQCoNiI55f1t7F/ysIKzp5XC7Gfr1ul+duMl9rNju+T5kzE/uRQ/1tg5",
    "Oe/1/PR58/hfLrYrjNndTMyzlLAzuBU89p79sv/BH799+9OHT728tfbnPPM/vnm+/f9WPL5z3Gh",
    "PFs5wQq8G+3AsrqUU/++P+V+Jx+qJv9X9ap3SJ/fc5mbZa33Z1cVnDyN/v96YHu87iXiPr6+ajo",
    "8qi/QpnaobP5iYMQlH27XxvzUW7/IMPq7H10e/v7+Yz/69QtI+ja9rCb7M2C51isWEfl89jpXCf",
    "PaT86flsZzIw4x90J5wR/aN3Pl0mR/zyyxqBSnrKy2PfCKPleMkHh8VovP3R4VF6OJoBh+NBB9m",
    "bH/WbkjRx51uNWp57XqxVStut3fvrt/dIG0tBOuKgzb4rM1ot+0TzUi3LQl3cQ9pB/gkgn3Y3O6",
    "Ya2v+ZdDF+gwels7wsIRP3uBGfeRN6+HF85Ee/nm+ED0czODBTujBnlsPkvfX/LemP6T1uei5Ir",
    "b33rQefnZHeijAQvTw4ww+ugk+ugvvDx3f6W/c21q/34l47oUslsuVXhahl99jvTy9GL04CT6c1",
    "6AXvfHgweZ9IpOCudLLVX9J0Yvy5KYjeH/B/WV1IXqZ9Z5yO8HP7eh7VIeYt1zoOJ92doUzAI1v",
    "rmefw1/1vey8dtaV3aWwy/0P83uZ7ywXbWddsN28+Z33e9Nlw097r7MS+JVLnMe83wFfN/4v63z",
    "PJR/F489PPsnbHmVuytfZ+HYNSC/t7n9Ap/8CeYaPAA==",
    ""
  };

  static char newstr [1621] = "";
  newstr[0] = '\0';
  for (i = 0; i < 23; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c4_RocketSim(SimStruct *S)
{
  const char* newstr = sf_c4_RocketSim_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(2007460437U));
  ssSetChecksum1(S,(1571802137U));
  ssSetChecksum2(S,(1751128732U));
  ssSetChecksum3(S,(3509452802U));
}

static void mdlRTW_c4_RocketSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c4_RocketSim(SimStruct *S)
{
  SFc4_RocketSimInstanceStruct *chartInstance;
  chartInstance = (SFc4_RocketSimInstanceStruct *)utMalloc(sizeof
    (SFc4_RocketSimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc4_RocketSimInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  if (ssGetSampleTime(S, 0) == CONTINUOUS_SAMPLE_TIME && ssGetOffsetTime(S, 0) ==
      0 && ssGetNumContStates(ssGetRootSS(S)) > 0 &&
      !supportsLegacyBehaviorForPersistentVarInContinuousTime(S)) {
    sf_error_out_about_continuous_sample_time_with_persistent_vars(S);
  }

  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_RocketSim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c4_RocketSim;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c4_RocketSim;
  chartInstance->chartInfo.mdlTerminate = sf_opaque_mdl_terminate_c4_RocketSim;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c4_RocketSim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_RocketSim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_RocketSim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_RocketSim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_RocketSim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c4_RocketSim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_RocketSim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_RocketSim;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->chartInfo.chartStateSetterFcn = NULL;
  chartInstance->chartInfo.chartStateGetterFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0,
    chartInstance->c4_JITStateAnimation,
    chartInstance->c4_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c4_RocketSim(chartInstance);
}

void c4_RocketSim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c4_RocketSim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_RocketSim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_RocketSim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_RocketSim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
