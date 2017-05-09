# -*- coding: utf-8 -*-
"""
Created on Wed Sep 11 16:36:03 2013

@author: Leo

Augumented by FrozenMap on Tue May 9 15:24:00 2017
"""

import pygame

SCREEN_WIDTH = 480
SCREEN_HEIGHT = 800

TYPE_SMALL = 1
TYPE_MIDDLE = 2
TYPE_BIG = 3

# 子弹类
class Bullet(pygame.sprite.Sprite):
	def __init__(self, bullet_img, init_pos):
		pygame.sprite.Sprite.__init__(self)
		self.image = bullet_img
		self.rect = self.image.get_rect()
		self.rect.midbottom = init_pos
		# 直接加减速度, 其实这里省掉了单位时间, d = v * t
		self.speed = 10

	def move(self):
		self.rect.top -= self.speed

# 玩家类
class Player(pygame.sprite.Sprite):
	def __init__(self, plane_img, player_rect, init_pos):
		pygame.sprite.Sprite.__init__(self)
		self.image = []
		# 用来存储玩家对象精灵图片的列表
		for i in range(len(player_rect)):
			self.image.append(plane_img.subsurface(player_rect[i]).convert_alpha())
		self.rect = player_rect[0]                      # 初始化图片所在的矩形
		self.rect.topleft = init_pos                    # 初始化矩形的左上角坐标
		self.speed = 8                                  # 初始化玩家速度，这里是一个确定的值
		self.bullets = pygame.sprite.Group()            # 玩家飞机所发射的子弹的集合
		self.img_index = 0                              # 玩家精灵图片索引
		self.is_hit = False                             # 玩家是否被击中

	def shoot(self, bullet_img):
		bullet = Bullet(bullet_img, self.rect.midtop)
		self.bullets.add(bullet)
		# print(self.rect.midtop)

	def awesome_shoot(self, bullet_img):
		bullet = Bullet(bullet_img, self.rect.midtop)
		self.bullets.add(bullet)
		pos1 = self.rect.midtop
		bullet = Bullet(bullet_img, (pos1[0] - 30, pos1[1]) )
		self.bullets.add(bullet)
		bullet = Bullet(bullet_img, (pos1[0] - 60, pos1[1]) )
		self.bullets.add(bullet)
		bullet = Bullet(bullet_img, (pos1[0] + 30, pos1[1]) )
		self.bullets.add(bullet)
		bullet = Bullet(bullet_img, (pos1[0] + 60, pos1[1]) )
		self.bullets.add(bullet)
		# 还可以想一想如何做出发散的效果, 在Bullet.move()上做文章


	def moveUp(self):
		if self.rect.top <= 0:
			self.rect.top = 0
		else:
			self.rect.top -= self.speed

	def moveDown(self):
		if self.rect.top >= SCREEN_HEIGHT - self.rect.height:
			self.rect.top = SCREEN_HEIGHT - self.rect.height
		else:
			self.rect.top += self.speed

	def moveLeft(self):
		if self.rect.left <= 0:
			self.rect.left = 0
		else:
			self.rect.left -= self.speed

	def moveRight(self):
		if self.rect.left >= SCREEN_WIDTH - self.rect.width:
			self.rect.left = SCREEN_WIDTH - self.rect.width
		else:
			self.rect.left += self.speed

# 敌人类
class Enemy(pygame.sprite.Sprite):
	def __init__(self, enemy_img, enemy_down_imgs, init_pos):
	   pygame.sprite.Sprite.__init__(self)
	   self.image = enemy_img
	   self.rect = self.image.get_rect()
	   self.rect.topleft = init_pos
	   self.down_imgs = enemy_down_imgs
	   self.speed = 2
	   self.down_index = 0

	def move(self):
		self.rect.top += self.speed