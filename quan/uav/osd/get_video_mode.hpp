#ifndef QUAN_UAV_OSD_GET_VIDEO_MODE_HPP_INCLUDED
#define QUAN_UAV_OSD_GET_VIDEO_MODE_HPP_INCLUDED

namespace quan{ namespace uav { namespace osd{

   enum class video_mode { unknown, ntsc, pal };

   video_mode  get_video_mode();

}}}

#endif // QUAN_UAV_OSD_GET_VIDEO_MODE_HPP_INCLUDED
