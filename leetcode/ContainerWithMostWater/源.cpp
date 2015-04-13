#include <algorithm>
#include <vector>
#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        
        int maxc(numeric_limits<int>::min());
        //int tmax(numeric_limits<int>::min());
        //int tmin(0);

        for (auto i = 0; i < height.size() - 1; ++i)
        {
            for (int j = height.size() - 1; j > i; --j)
            {
                if (height.at(j) >= height.at(i))
                {
                    maxc = max(maxc, height.at(i)*(j - i));
                    break;
                }
                else
                {
                    maxc = max(maxc, height.at(j)*(j - i));
                }
            }
            while (i + 1 < height.size() - 1 && height.at(i) >= height.at(i + 1))
                ++i;
        }
        return maxc;
    }
};


int main()
{
    Solution s;
    vector<vector<int>> tests = {
        {3,2,1,2},
        {3,7,5,7,1,10},
        {3,100,107,50},
        {15000, 14999, 14998, 14997, 14996, 14995, 14994, 14993, 14992, 14991, 14990, 14989, 14988, 14987, 14986, 14985, 14984, 14983, 14982, 14981, 14980, 14979, 14978, 14977, 14976, 14975, 14974, 14973, 14972, 14971, 14970, 14969, 14968, 14967, 14966, 14965, 14964, 14963, 14962, 14961, 14960, 14959, 14958, 14957, 14956, 14955, 14954, 14953, 14952, 14951, 14950, 14949, 14948, 14947, 14946, 14945, 14944, 14943, 14942, 14941, 14940, 14939, 14938, 14937, 14936, 14935, 14934, 14933, 14932, 14931, 14930, 14929, 14928, 14927, 14926, 14925, 14924, 14923, 14922, 14921, 14920, 14919, 14918, 14917, 14916, 14915, 14914, 14913, 14912, 14911, 14910, 14909, 14908, 14907, 14906, 14905, 14904, 14903, 14902, 14901, 14900, 14899, 14898, 14897, 14896, 14895, 14894, 14893, 14892, 14891, 14890, 14889, 14888, 14887, 14886, 14885, 14884, 14883, 14882, 14881, 14880, 14879, 14878, 14877, 14876, 14875, 14874, 14873, 14872, 14871, 14870, 14869, 14868, 14867, 14866, 14865, 14864, 14863, 14862, 14861, 14860, 14859, 14858, 14857, 14856, 14855, 14854, 14853, 14852, 14851, 14850, 14849, 14848, 14847, 14846, 14845, 14844, 14843, 14842, 14841, 14840, 14839, 14838, 14837, 14836, 14835, 14834, 14833, 14832, 14831, 14830, 14829, 14828, 14827, 14826, 14825, 14824, 14823, 14822, 14821, 14820, 14819, 14818, 14817, 14816, 14815, 14814, 14813, 14812, 14811, 14810, 14809, 14808, 14807, 14806, 14805, 14804, 14803, 14802, 14801, 14800, 14799, 14798, 14797, 14796, 14795, 14794, 14793, 14792, 14791, 14790, 14789, 14788, 14787, 14786, 14785, 14784, 14783, 14782, 14781, 14780, 14779, 14778, 14777, 14776, 14775, 14774, 14773, 14772, 14771, 14770, 14769, 14768, 14767, 14766, 14765, 14764, 14763, 14762, 14761, 14760, 14759, 14758, 14757, 14756, 14755, 14754, 14753, 14752, 14751, 14750, 14749, 14748, 14747, 14746, 14745, 14744, 14743, 14742, 14741, 14740, 14739, 14738, 14737, 14736, 14735, 14734, 14733, 14732, 14731, 14730, 14729, 14728, 14727, 14726, 14725, 14724, 14723, 14722, 14721, 14720, 14719, 14718, 14717, 14716, 14715, 14714, 14713, 14712, 14711, 14710, 14709, 14708, 14707, 14706, 14705, 14704, 14703, 14702, 14701, 14700, 14699, 14698, 14697, 14696, 14695, 14694, 14693, 14692, 14691, 14690, 14689, 14688, 14687, 14686, 14685, 14684, 14683, 14682, 14681, 14680, 14679, 14678, 14677, 14676, 14675, 14674, 14673, 14672, 14671, 14670, 14669, 14668, 14667, 14666, 14665, 14664, 14663, 14662, 14661, 14660, 14659, 14658, 14657, 14656, 14655, 14654, 14653, 14652, 14651, 14650, 14649, 14648, 14647, 14646, 14645, 14644, 14643, 14642, 14641, 14640, 14639, 14638, 14637, 14636, 14635, 14634, 14633, 14632, 14631, 14630, 14629, 14628, 14627, 14626, 14625, 14624, 14623, 14622, 14621, 14620, 14619, 14618, 14617, 14616, 14615, 14614, 14613, 14612, 14611, 14610, 14609, 14608, 14607, 14606, 14605, 14604, 14603, 14602, 14601, 14600, 14599, 14598, 14597, 14596, 14595, 14594, 14593, 14592, 14591, 14590, 14589, 14588, 14587, 14586, 14585, 14584, 14583, 14582, 14581, 14580, 14579, 14578, 14577, 14576, 14575, 14574, 14573, 14572, 14571, 14570, 14569, 14568, 14567, 14566, 14565, 14564, 14563, 14562, 14561, 14560, 14559, 14558, 14557, 14556, 14555, 14554, 14553, 14552, 14551, 14550, 14549, 14548, 14547, 14546, 14545, 14544, 14543, 14542, 14541, 14540, 14539, 14538, 14537, 14536, 14535, 14534, 14533, 14532, 14531, 14530, 14529, 14528, 14527, 14526, 14525, 14524, 14523, 14522, 14521, 14520, 14519, 14518, 14517, 14516, 14515, 14514, 14513, 14512, 14511, 14510, 14509, 14508, 14507, 14506, 14505, 14504, 14503, 14502, 14501, 14500, 14499, 14498, 14497, 14496, 14495, 14494, 14493, 14492, 14491, 14490, 14489, 14488, 14487, 14486, 14485, 14484, 14483, 14482, 14481, 14480, 14479, 14478, 14477, 14476, 14475, 14474, 14473, 14472, 14471, 14470, 14469, 14468, 14467, 14466, 14465, 14464, 14463, 14462, 14461, 14460, 14459, 14458, 14457, 14456, 14455, 14454, 14453, 14452, 14451, 14450, 14449, 14448, 14447, 14446, 14445, 14444, 14443, 14442, 14441, 14440, 14439, 14438, 14437, 14436, 14435, 14434, 14433, 14432, 14431, 14430, 14429, 14428, 14427, 14426, 14425, 14424, 14423, 14422, 14421, 14420, 14419, 14418, 14417, 14416, 14415, 14414, 14413, 14412, 14411, 14410, 14409, 14408, 14407, 14406, 14405, 14404, 14403, 14402, 14401, 14400, 14399, 14398, 14397, 14396, 14395, 14394, 14393, 14392, 14391, 14390, 14389, 14388, 14387, 14386, 14385, 14384, 14383, 14382, 14381, 14380, 14379, 14378, 14377, 14376, 14375, 14374, 14373, 14372, 14371, 14370, 14369, 14368, 14367, 14366, 14365, 14364, 14363, 14362, 14361, 14360, 14359, 14358, 14357, 14356, 14355, 14354, 14353, 14352, 14351, 14350, 14349, 14348, 14347, 14346, 14345, 14344, 14343, 14342, 14341, 14340, 14339, 14338, 14337, 14336, 14335, 14334, 14333, 14332, 14331, 14330, 14329, 14328, 14327, 14326, 14325, 14324, 14323, 14322, 14321, 14320, 14319, 14318, 14317, 14316, 14315, 14314, 14313, 14312, 14311, 14310, 14309, 14308, 14307, 14306, 14305, 14304, 14303, 14302, 14301, 14300, 14299, 14298, 14297, 14296, 14295, 14294, 14293, 14292, 14291, 14290, 14289, 14288, 14287, 14286, 14285, 14284, 14283, 14282, 14281, 14280, 14279, 14278, 14277, 14276, 14275, 14274, 14273, 14272, 14271, 14270, 14269, 14268, 14267, 14266, 14265, 14264, 14263, 14262, 14261, 14260, 14259, 14258, 14257, 14256, 14255, 14254, 14253, 14252, 14251, 14250, 14249, 14248, 14247, 14246, 14245, 14244, 14243, 14242, 14241, 14240, 14239, 14238, 14237, 14236, 14235, 14234, 14233, 14232, 14231, 14230, 14229, 14228, 14227, 14226, 14225, 14224, 14223, 14222, 14221, 14220, 14219, 14218, 14217, 14216, 14215, 14214, 14213, 14212, 14211, 14210, 14209, 14208, 14207, 14206, 14205, 14204, 14203, 14202, 14201, 14200, 14199, 14198, 14197, 14196, 14195, 14194, 14193, 14192, 14191, 14190, 14189, 14188, 14187, 14186, 14185, 14184, 14183, 14182, 14181, 14180, 14179, 14178, 14177, 14176, 14175, 14174, 14173, 14172, 14171, 14170, 14169, 14168, 14167, 14166, 14165, 14164, 14163, 14162, 14161, 14160, 14159, 14158, 14157, 14156, 14155, 14154, 14153, 14152, 14151, 14150, 14149, 14148, 14147, 14146, 14145, 14144, 14143, 14142, 14141, 14140, 14139, 14138, 14137, 14136, 14135, 14134, 14133, 14132, 14131, 14130, 14129, 14128, 14127, 14126, 14125, 14124, 14123, 14122, 14121, 14120, 14119, 14118, 14117, 14116, 14115, 14114, 14113, 14112, 14111, 14110, 14109, 14108, 14107, 14106, 14105, 14104, 14103, 14102, 14101, 14100, 14099, 14098, 14097, 14096, 14095, 14094, 14093, 14092, 14091, 14090, 14089, 14088, 14087, 14086, 14085, 14084, 14083, 14082, 14081, 14080, 14079, 14078, 14077, 14076, 14075, 14074, 14073, 14072, 14071, 14070, 14069, 14068, 14067, 14066, 14065, 14064, 14063, 14062, 14061, 14060, 14059, 14058, 14057, 14056, 14055, 14054, 14053, 14052, 14051, 14050, 14049, 14048, 14047, 14046, 14045, 14044, 14043, 14042, 14041, 14040, 14039, 14038, 14037, 14036, 14035, 14034, 14033, 14032, 14031, 14030, 14029, 14028, 14027, 14026, 14025, 14024, 14023, 14022, 14021, 14020, 14019, 14018, 14017, 14016, 14015, 14014, 14013, 14012, 14011, 14010, 14009, 14008, 14007, 14006, 14005, 14004, 14003, 14002, 14001, 14000, 13999, 13998, 13997, 13996, 13995, 13994, 13993, 13992, 13991, 13990, 13989, 13988, 13987, 13986, 13985, 13984, 13983, 13982, 13981, 13980, 13979, 13978, 13977, 13976, 13975, 13974, 13973, 13972, 13971, 13970, 13969, 13968, 13967, 13966, 13965, 13964, 13963, 13962, 13961, 13960, 13959, 13958, 13957, 13956, 13955, 13954, 13953, 13952, 13951, 13950, 13949, 13948, 13947, 13946, 13945, 13944, 13943, 13942, 13941, 13940, 13939, 13938, 13937, 13936, 13935, 13934, 13933, 13932, 13931, 13930, 13929, 13928, 13927, 13926, 13925, 13924, 13923, 13922, 13921, 13920, 13919, 13918, 13917, 13916, 13915, 13914, 13913, 13912, 13911, 13910, 13909, 13908, 13907, 13906, 13905, 13904, 13903, 13902, 13901, 13900, 13899, 13898, 13897, 13896, 13895, 13894, 13893, 13892, 13891, 13890, 13889, 13888, 13887, 13886, 13885, 13884, 13883, 13882, 13881, 13880, 13879, 13878, 13877, 13876, 13875, 13874, 13873, 13872, 13871, 13870, 13869, 13868, 13867, 13866, 13865, 13864, 13863, 13862, 13861, 13860, 13859, 13858, 13857, 13856, 13855, 13854, 13853, 13852, 13851, 13850, 13849, 13848, 13847, 13846, 13845, 13844, 13843, 13842, 13841, 13840, 13839, 13838, 13837, 13836, 13835, 13834, 13833, 13832, 13831, 13830, 13829, 13828, 13827, 13826, 13825, 13824, 13823, 13822, 13821, 13820, 13819, 13818, 13817, 13816, 13815, 13814, 13813, 13812, 13811, 13810, 13809, 13808, 13807, 13806, 13805, 13804, 13803, 13802, 13801, 13800, 13799, 13798, 13797, 13796, 13795, 13794, 13793, 13792, 13791, 13790, 13789, 13788, 13787, 13786, 13785, 13784, 13783, 13782, 13781, 13780, 13779, 13778, 13777, 13776, 13775, 13774, 13773, 13772, 13771, 13770, 13769, 13768, 13767, 13766, 13765, 13764, 13763, 13762, 13761, 13760, 13759, 13758, 13757, 13756, 13755, 13754, 13753, 13752, 13751, 13750, 13749, 13748, 13747, 13746, 13745, 13744, 13743, 13742, 13741, 13740, 13739, 13738, 13737, 13736, 13735, 13734, 13733, 13732, 13731, 13730, 13729, 13728, 13727, 13726, 13725, 13724, 13723, 13722, 13721, 13720, 13719, 13718, 13717, 13716, 13715, 13714, 13713, 13712, 13711, 13710, 13709, 13708, 13707, 13706, 13705, 13704, 13703, 13702, 13701, 13700, 13699, 13698, 13697, 13696, 13695, 13694, 13693, 13692, 13691, 13690, 13689, 13688, 13687, 13686, 13685, 13684, 13683, 13682, 13681, 13680, 13679, 13678, 13677, 13676, 13675, 13674, 13673, 13672, 13671, 13670, 13669, 13668, 13667, 13666, 13665, 13664, 13663, 13662, 13661, 13660, 13659, 13658, 13657, 13656, 13655, 13654, 13653, 13652, 13651, 13650, 13649, 13648, 13647, 13646, 13645, 13644, 13643, 13642, 13641, 13640, 13639, 13638, 13637, 13636, 13635, 13634, 13633, 13632, 13631, 13630, 13629, 13628, 13627, 13626, 13625, 13624, 13623, 13622, 13621, 13620, 13619, 13618, 13617, 13616, 13615, 13614, 13613, 13612, 13611, 13610, 13609, 13608, 13607, 13606, 13605, 13604, 13603, 13602, 13601, 13600, 13599, 13598, 13597, 13596, 13595, 13594, 13593, 13592, 13591, 13590, 13589, 13588, 13587, 13586, 13585, 13584, 13583, 13582, 13581, 13580, 13579, 13578, 13577, 13576, 13575, 13574, 13573, 13572, 13571, 13570, 13569, 13568, 13567, 13566, 13565, 13564, 13563, 13562, 13561, 13560, 13559, 13558, 13557, 13556, 13555, 13554, 13553, 13552, 13551, 13550, 13549, 13548, 13547, 13546, 13545, 13544, 13543, 13542, 13541, 13540, 13539, 13538, 13537, 13536, 13535, 13534, 13533, 13532, 13531, 13530, 13529, 13528, 13527, 13526, 13525, 13524, 13523, 13522, 13521, 13520, 13519, 13518, 13517, 13516, 13515, 13514, 13513, 13512, 13511, 13510, 13509, 13508, 13507, 13506, 13505, 13504, 13503, 13502, 13501, 13500, 13499, 13498, 13497, 13496, 13495, 13494, 13493, 13492, 13491, 13490, 13489, 13488, 13487, 13486, 13485, 13484, 13483, 13482, 13481, 13480, 13479, 13478, 13477, 13476, 13475, 13474, 13473, 13472, 13471, 13470, 13469, 13468, 13467, 13466, 13465, 13464, 13463, 13462, 13461, 13460, 13459, 13458, 13457, 13456, 13455, 13454, 13453, 13452, 13451, 13450, 13449, 13448, 13447, 13446, 13445, 13444, 13443, 13442, 13441, 13440, 13439, 13438, 13437, 13436, 13435, 13434, 13433, 13432, 13431, 13430, 13429, 13428, 13427, 13426, 13425, 13424, 13423, 13422, 13421, 13420, 13419, 13418, 13417, 13416, 13415, 13414, 13413, 13412, 13411, 13410, 13409, 13408, 13407, 13406, 13405, 13404, 13403, 13402, 13401, 13400, 13399, 13398, 13397, 13396, 13395, 13394, 13393, 13392, 13391, 13390, 13389, 13388, 13387, 13386, 13385, 13384, 13383, 13382, 13381, 13380, 13379, 13378, 13377, 13376, 13375, 13374, 13373, 13372, 13371, 13370, 13369, 13368, 13367, 13366, 13365, 13364, 13363, 13362, 13361, 13360, 13359, 13358, 13357, 13356, 13355, 13354, 13353, 13352, 13351, 13350, 13349, 13348, 13347, 13346, 13345, 13344, 13343, 13342, 13341, 13340, 13339, 13338, 13337, 13336, 13335}
    };
    for (auto t : tests)
    {
        cout << s.maxArea(t) << endl;
    }
    system("pause");
}