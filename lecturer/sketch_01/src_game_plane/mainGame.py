# -*- coding: utf-8 -*-
'''
Created on Wed Sep 11 11:05:00 2013

@author: Leo

Augumented by FrozenMap on Tue May 9 15:24:00 2017
'''

import pygame
from sys import exit
from pygame.locals import *
from gameRole import *
import random


# initialization
pygame.init()
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption('飞机大战')

# 载入游戏音乐
bullet_sound = pygame.mixer.Sound('resources/sound/bullet.wav')
enemy1_down_sound = pygame.mixer.Sound('resources/sound/enemy1_down.wav')
game_over_sound = pygame.mixer.Sound('resources/sound/game_over.wav')
bullet_sound.set_volume(0.3)
enemy1_down_sound.set_volume(0.3)
game_over_sound.set_volume(0.3)
pygame.mixer.music.load('resources/sound/game_music.wav')
pygame.mixer.music.play(-1, 0.0)
pygame.mixer.music.set_volume(0.25)

# 载入背景图
background = pygame.image.load('resources/image/background.png').convert()
game_over = pygame.image.load('resources/image/gameover.png')

# 原画素材, 包括各种飞机和子弹
filename = 'resources/image/shoot.png'
plane_img = pygame.image.load(filename)


# 设置UI参数, 以topLeft为原点, 向右为+x, 向下为+y, (x, y, xSpan, ySpan)
player_rect = []

# 玩家飞机原型0, 飞机原型
player_rect.append(pygame.Rect(0, 99, 102, 126))
# 玩家飞机原型1, 与1不断切换, 形成动态喷气动画效果
# 什么是动画，动画就是一帧一帧连起来的画, 视觉停留, 造成动画效果
player_rect.append(pygame.Rect(165, 360, 102, 126))

# 玩家飞机原型2, 飞机爆炸图片, 小
player_rect.append(pygame.Rect(165, 234, 102, 126))
# 玩家飞机原型3, 飞机爆炸图片, 中
player_rect.append(pygame.Rect(330, 624, 102, 126))
# 玩家飞机原型4, 飞机爆炸图片, 大
player_rect.append(pygame.Rect(330, 498, 102, 126))
# 玩家飞机原型5, 飞机爆炸图片, 灰烬. 由小到大再到灰烬形成爆炸的动画效果
player_rect.append(pygame.Rect(432, 624, 102, 126))

# 玩家初始位置
player_init_position = [200, 600]
# 构造实例对象
player = Player(plane_img, player_rect, player_init_position)


# 子弹对象的原画, 在最右下角
bullet_rect = pygame.Rect(1004, 987, 9, 21)
bullet_img = plane_img.subsurface(bullet_rect)


# 敌机原型, 在第4排第5列
enemy1_rect = pygame.Rect(534, 612, 57, 43)
enemy1_img = plane_img.subsurface(enemy1_rect)

# 敌机被击中的分镜原型
enemy1_down_imgs = []
enemy1_down_imgs.append(plane_img.subsurface(pygame.Rect(267, 347, 57, 43)))
enemy1_down_imgs.append(plane_img.subsurface(pygame.Rect(873, 697, 57, 43)))
enemy1_down_imgs.append(plane_img.subsurface(pygame.Rect(267, 296, 57, 43)))
enemy1_down_imgs.append(plane_img.subsurface(pygame.Rect(930, 697, 57, 43)))

# 该结构组用于存储没有被击毁的敌机
enemies1 = pygame.sprite.Group()

# 该结构组用于存储被击毁的飞机
enemies_down = pygame.sprite.Group()

shoot_frequency = 0
enemy_frequency = 0

player_down_index = 16

score = 0

clock = pygame.time.Clock()

running = True

while running:
	# 控制游戏最大帧率为60(每秒最多刷新60次)
	# http://www.pygame.org/docs/ref/time.html#pygame.time.Clock.tick
	clock.tick(60)

	# 控制发射子弹频率,并发射子弹
	if not player.is_hit:
		# 15改成1 则是每一帧都发射子弹, 相当于开启作弊模式
		if shoot_frequency % 15 == 0:
		# if shoot_frequency % 1 == 0: 
			bullet_sound.play()
			# 累计15帧的时间, 进行一次子弹发射, 即1/4秒发射一次
			player.shoot(bullet_img)
			# player.awesome_shoot(bullet_img)
		# 每一帧 shoot_frequency += 1
		shoot_frequency += 1
		if shoot_frequency >= 15:
			shoot_frequency = 0

	# 生成敌机
	if enemy_frequency % 50 == 0:
		# 每50帧刷新一架敌机, 即5/6秒出现一架新的敌机
		# 初始位置: x为随机, y为0
		enemy1_pos = [random.randint(0, SCREEN_WIDTH - enemy1_rect.width), 0]
		enemy1 = Enemy(enemy1_img, enemy1_down_imgs, enemy1_pos)
		enemies1.add(enemy1)
	enemy_frequency += 1
	if enemy_frequency >= 100:
		enemy_frequency = 0

	# 移动子弹, 若子弹底部的y坐标<0, 则删除
	for bullet in player.bullets:
		bullet.move()
		if bullet.rect.bottom < 0:
			player.bullets.remove(bullet)

	# 移动敌机，若超出窗口范围则删除
	for enemy in enemies1:
		enemy.move()
		# 判断玩家是否被击中
		if pygame.sprite.collide_circle(enemy, player):
			enemies_down.add(enemy)
			enemies1.remove(enemy)
			# 注释掉下面这行就可以开启无敌
			player.is_hit = True
			game_over_sound.play()
			break
		if enemy.rect.top > SCREEN_HEIGHT:
			enemies1.remove(enemy)

	# 将被击中的敌机对象添加到击毁敌机Group中
	enemies1_down = pygame.sprite.groupcollide(enemies1, player.bullets, 1, 1)
	for enemy_down in enemies1_down:
		enemies_down.add(enemy_down)

	# 绘制背景
	screen.fill(0)
	# https://www.pygame.org/docs/ref/surface.html#pygame.Surface.blit
	# blit() ---> 以background为源, 以(0, 0)为目标起点, draw image
	screen.blit(background, (0, 0))

	# 绘制玩家飞机
	if not player.is_hit:
		# 在当前位置更新玩家飞机的图片(状态)
		screen.blit(player.image[player.img_index], player.rect)
		# img_index在[0, 1]之间切换(即飞机原型0, 1), 造成喷气效果
		player.img_index = shoot_frequency // 8
	else:
		# 被击中的飞机从原型2开始
		player.img_index = player_down_index // 8
		# 在当前位置更新玩家飞机的图片(状态)
		screen.blit(player.image[player.img_index], player.rect)
		player_down_index += 1
		# 48 // 8 == 6, 已完成飞机原型5的更新, 玩家飞机已经爆炸完毕, 游戏将结束
		if player_down_index > 47:
			running = False

	# 绘制击毁敌机的动画
	for enemy_down in enemies_down:
		# 首先播放爆炸音乐
		if enemy_down.down_index == 0:
			enemy1_down_sound.play()
		# 在8帧以后, 一架敌机已经爆炸完毕, 移除该敌机, 同时分数 +=1000
		if enemy_down.down_index > 7:
			enemies_down.remove(enemy_down)
			score += 1000
			continue
		# 敌机爆炸的原型有4个, 每2帧播放一个
		screen.blit(enemy_down.down_imgs[enemy_down.down_index // 2], enemy_down.rect)
		enemy_down.down_index += 1

	# 绘制子弹
	player.bullets.draw(screen)
	# 绘制未被击中的敌机
	enemies1.draw(screen)

	# 绘制得分
	score_font = pygame.font.Font(None, 36)
	score_text = score_font.render(str(score), True, (128, 128, 128))
	text_rect = score_text.get_rect()
	text_rect.topleft = [10, 10]
	screen.blit(score_text, text_rect)

	# 全部blit画好之后, 一次性更新屏幕
	pygame.display.update()

	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			pygame.quit()
			exit()
			
	# 监听键盘事件
	key_pressed = pygame.key.get_pressed()
	if not player.is_hit:
		if key_pressed[K_w] or key_pressed[K_UP]:
			player.moveUp()
		if key_pressed[K_s] or key_pressed[K_DOWN]:
			player.moveDown()
		if key_pressed[K_a] or key_pressed[K_LEFT]:
			player.moveLeft()
		if key_pressed[K_d] or key_pressed[K_RIGHT]:
			player.moveRight()

# 战绩
font = pygame.font.Font(None, 48)
text = font.render('Score: '+ str(score), True, (255, 0, 0))
text_rect = text.get_rect()
text_rect.centerx = screen.get_rect().centerx
text_rect.centery = screen.get_rect().centery + 24
screen.blit(game_over, (0, 0))
screen.blit(text, text_rect)

while 1:
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			pygame.quit()
			exit()
	pygame.display.update()
