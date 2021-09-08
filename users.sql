/*
Navicat MySQL Data Transfer

Source Server         : lib
Source Server Version : 80026
Source Host           : localhost:3306
Source Database       : lib

Target Server Type    : MYSQL
Target Server Version : 80026
File Encoding         : 65001

Date: 2021-09-08 14:03:37
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for users
-- ----------------------------
DROP TABLE IF EXISTS `users`;
CREATE TABLE `users` (
  `user_id` int NOT NULL,
  `password` varchar(255) NOT NULL,
  `number` varchar(255) NOT NULL,
  `name` varchar(255) NOT NULL,
  `sex` varchar(255) NOT NULL,
  `department` varchar(255) NOT NULL,
  `grade` varchar(255) NOT NULL,
  PRIMARY KEY (`user_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of users
-- ----------------------------
INSERT INTO `users` VALUES ('1111', '1111', '4444', 'root', 'non', 's', '19');
