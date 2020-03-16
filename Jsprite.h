#ifndef		_JSPRITE_DOT_H_
#define		_JSPRITE_DOT_H_

//  Filename:		Jsprite.h
//	Author:			John Carlson
//	Description:	This is my class to encapsulate the business of dealing with sprites
//	
//	Changelog:		started 1-30-2003
//

#include "mygba.h"



struct VECT3D8{
	u8 x;   
	u8 y;   
	u8 z;   	
};

struct VECT3D16{
	u16 x;   
	u16 y;   
	u16 z;   	
};

//create variable and prototypes for get/set methods
#define SprAttr(_type_,_atname_)					\
private:											\
		u##_type_ f##_atname_;						\
public:												\
		u##_type_ get##_atname_();					\
		void set##_atname_(u##_type_ val);			\
private:											\


//implement get/set methods of specific attr
#define ImpSprAttr(_type_,_atname_)					\
													\
		u##_type_ Jsprite::get##_atname_(){			\
			return f##_atname_;}					\
													\
		void Jsprite::set##_atname_(u##_type_ val){	\
			f##_atname_ = val;}						\

//create 3D variable and prototypes for get/set methods
#define Spr3DAttr(_type_,_atname_)					\
private:											\
		struct VECT3D##_type_ f##_atname_;			\
public:												\
		u##_type_ getX##_atname_();					\
		void setX##_atname_(u##_type_ val);			\
		u##_type_ getY##_atname_();					\
		void setY##_atname_(u##_type_ val);			\
		u##_type_ getZ##_atname_();					\
		void setZ##_atname_(u##_type_ val);			\
private:											\


//implement get/set methods of specific 3D attr
#define ImpSpr3DAttr(_type_,_atname_)				\
													\
		u##_type_ Jsprite::getX##_atname_(){		\
			return f##_atname_##.x;}				\
													\
		void Jsprite::setX##_atname_(u##_type_ val){\
			f##_atname_##.x = val;}					\
													\
		u##_type_ Jsprite::getY##_atname_(){		\
			return f##_atname_##.y;}				\
													\
		void Jsprite::setY##_atname_(u##_type_ val){\
			f##_atname_##.y = val;}					\
													\
		u##_type_ Jsprite::getZ##_atname_(){		\
			return f##_atname_##.z;}				\
													\
		void Jsprite::setZ##_atname_(u##_type_ val){\
			f##_atname_##.z = val;}					\




class Jsprite
{
public:

		Jsprite();

		void initSprite(u8 sprnum,				//sprite index 0-127
						unsigned char* bmpsrc,	//ptr to bmp array
						u8 xscreen,				//x screen coord
						u8 yscreen				//y screen coord
						);

		void changeTexture();

private:

		//array of sprites for all instances of Jsprites
		SprAttr(8, SpriteNum)
		
		//this sprites index into above array
		SprAttr(8,Index)

		//sprites world location
		Spr3DAttr(16, Loc)            	

		//sprite dimensions
		SprAttr(8, Width)
		SprAttr(8, Height)

		//whether the sprite is visible or not
		bool fVisibility;

		//current direction		(unit velocity)
		Spr3DAttr(8, Dir)

        //speed sprite is travelling
		SprAttr(8, Speed)

		//number of frames of animation
		SprAttr(8, FramesOfAnim)

		//current frame of animation
		SprAttr(8, TextureIndex)
		
		//ptr to bitmap
		unsigned char* fBmpArray;
        


};

#endif

















