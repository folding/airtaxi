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
protected:											\
		u##_type_ f##_atname_;						\
public:												\
		u##_type_ get##_atname_();					\
		void set##_atname_(u##_type_ val);			\
protected:											\


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
protected:											\
		struct VECT3D##_type_ f##_atname_;			\
public:												\
		u##_type_ getX##_atname_();					\
		void setX##_atname_(u##_type_ val);			\
		u##_type_ getY##_atname_();					\
		void setY##_atname_(u##_type_ val);			\
		u##_type_ getZ##_atname_();					\
		void setZ##_atname_(u##_type_ val);			\
protected:											\


//implement get/set methods of specific 3D attr
#define ImpSpr3DAttr(_type_,_atname_)				\
													\
		u##_type_ Jsprite::getX##_atname_(){		\
			return f##_atname_.x;}					\
													\
		void Jsprite::setX##_atname_(u##_type_ val){\
			f##_atname_.x = val;}					\
													\
		u##_type_ Jsprite::getY##_atname_(){		\
			return f##_atname_.y;}					\
													\
		void Jsprite::setY##_atname_(u##_type_ val){\
			f##_atname_.y = val;}					\
													\
		u##_type_ Jsprite::getZ##_atname_(){		\
			return f##_atname_.z;}					\
													\
		void Jsprite::setZ##_atname_(u##_type_ val){\
			f##_atname_.z = val;}					\


//create bool variable and prototypes for methods
#define SprBoolAttr(_atname_)						\
protected:											\
		bool f##_atname_;							\
public:												\
		bool get##_atname_();						\
		void enable##_atname_();					\
		void disable##_atname_();					\
		void toggle##_atname_();					\
protected:											\


//implement bool methods
#define ImpSprBoolAttr(_atname_)					\
													\
		bool Jsprite::get##_atname_(){				\
			return f##_atname_;}					\
													\
		void Jsprite::enable##_atname_(){			\
			f##_atname_ = true;}					\
													\
		void Jsprite::disable##_atname_(){			\
			f##_atname_ = false;}					\
													\
		void Jsprite::toggle##_atname_(){			\
			f##_atname_ = !f##_atname_;}			\


class Jsprite
{
public:

		Jsprite();

		void initSprite(unsigned char* bmpsrc,	//ptr to bmp array
						u8 fxmode,				//display sprite normal(nofx)
						u8 palmode,				//color/palette mode
						u8 palindex,			//palette index if mode 0
						u8 mosaic,				//support mosaic (0 = off)
						u8 hflip,				//horiz flip on/off
						u8 vflip,				//vert flip on/off
						u8 prio,				//priority(0-high, 3-low)
						u8 dblsize,				//doublesize on/off
						u16 xscreen,			//x screen coord
						u16 yscreen,			//y screen coord
						u8 height,				//sprite height
						u8 width,				//sprite width
						u8 numtexts,			//number of textures
						u8 tindex				//starting texture
						);



		void changeTexture();

private:

protected:

		//handle to the sprite in mem set by createObj call
		SprAttr(8, SpriteNum)
		
		//sprites world location
		Spr3DAttr(16, Loc)            	

		//sprite dimensions
		SprAttr(8, Width)
		SprAttr(8, Height)

		//whether the sprite is visible or not
		SprBoolAttr(Visibility)

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

















