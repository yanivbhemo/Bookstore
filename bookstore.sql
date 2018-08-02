CREATE DATABASE  IF NOT EXISTS `bookstore` /*!40100 DEFAULT CHARACTER SET latin1 */;
USE `bookstore`;
-- MySQL dump 10.13  Distrib 5.7.17, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: bookstore
-- ------------------------------------------------------
-- Server version	5.5.5-10.1.32-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `book`
--

DROP TABLE IF EXISTS `book`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `book` (
  `ISBN` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `price` int(4) DEFAULT NULL,
  `quantity` int(5) DEFAULT NULL,
  `status` varchar(45) CHARACTER SET latin1 DEFAULT NULL,
  PRIMARY KEY (`ISBN`),
  CONSTRAINT `ISBN` FOREIGN KEY (`ISBN`) REFERENCES `book_catalog` (`ISBN`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=51 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `book`
--

LOCK TABLES `book` WRITE;
/*!40000 ALTER TABLE `book` DISABLE KEYS */;
INSERT INTO `book` VALUES (1,78,7,NULL),(2,52,14,NULL),(3,79,8,NULL),(4,98,5,NULL),(5,60,0,NULL),(6,68,13,NULL),(7,65,15,NULL),(8,30,6,NULL),(9,41,12,NULL),(10,62,0,NULL),(11,91,0,NULL),(12,77,12,NULL),(13,61,9,NULL),(14,82,12,NULL),(15,75,5,NULL),(16,34,0,NULL),(17,79,12,NULL),(18,64,8,NULL),(19,43,8,NULL),(20,58,11,NULL),(21,40,8,NULL),(22,58,9,NULL),(23,97,14,NULL),(24,63,6,NULL),(25,79,13,NULL),(26,58,9,NULL),(27,93,6,NULL),(28,99,0,NULL),(29,79,15,NULL),(30,71,8,NULL),(31,58,0,NULL),(32,43,9,NULL),(33,92,7,NULL),(34,91,0,NULL),(35,38,15,NULL),(36,61,15,NULL),(37,34,0,NULL),(38,51,9,NULL),(39,49,10,NULL),(40,50,9,NULL),(41,73,6,NULL),(42,90,10,NULL),(43,72,0,NULL),(44,57,8,NULL),(45,46,7,NULL),(46,50,0,NULL),(47,88,14,NULL),(48,49,0,NULL),(49,30,13,NULL),(50,93,7,NULL);
/*!40000 ALTER TABLE `book` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `book_catalog`
--

DROP TABLE IF EXISTS `book_catalog`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `book_catalog` (
  `ISBN` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `author` varchar(45) NOT NULL,
  `title` varchar(45) NOT NULL,
  `publisher` varchar(45) NOT NULL,
  `issue_date` date NOT NULL,
  `discount` int(2) DEFAULT NULL,
  PRIMARY KEY (`ISBN`)
) ENGINE=InnoDB AUTO_INCREMENT=51 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `book_catalog`
--

LOCK TABLES `book_catalog` WRITE;
/*!40000 ALTER TABLE `book_catalog` DISABLE KEYS */;
INSERT INTO `book_catalog` VALUES (1,'Osmund Stickles','Multi-lateral','Hammes, Wyman and Bruen','1977-07-19',NULL),(2,'Tarrah Llorens','Intuitive 24 hour project','Swaniawski, Schumm and Connelly','1967-05-20',NULL),(3,'Laureen Albertson','Inverse explicit artificial intelligence','Baumbach LLC','2015-06-13',4),(4,'Erik Antoniottii','Public-key even-keeled system engine','Osinski-Hilpert','1956-07-20',NULL),(5,'Viviyan Stocky','Upgradable logistical definition','Bayer-Feest','1942-12-18',NULL),(6,'Brigitta Arling','Integrated well-modulated emulation','Harvey, Torphy and Zulauf','2008-06-02',NULL),(7,'Fanya Pawelec','Seamless actuating encoding','Bartell, Marvin and Becker','1979-02-28',4),(8,'Kip Shepherd','Open-source 3rd generation complexity','Fahey, Goodwin and Wolff','1983-03-21',NULL),(9,'Jamal Reye','Implemented bi-directional pricing structure','Kertzmann, Renner and Yost','2005-02-18',NULL),(10,'Corissa Frawley','Future-proofed high-level time-frame','Harber, Bins and Bogisich','1967-10-21',NULL),(11,'Felicity Bourthoumieux','Fully-configurable background model','Schneider LLC','2007-12-31',NULL),(12,'Ora Kubalek','Pre-emptive responsive hierarchy','Beer, Hartmann and Wunsch','2005-10-05',NULL),(13,'Lonna Rechert','Reactive secondary attitude','Hansen, Upton and Schinner','2006-03-08',4),(14,'Elroy Grimsell','Implemented well-modulated analyzer','Hayes LLC','2001-03-04',NULL),(15,'Zeb Effemy','Managed analyzing focus group','Greenholt, Schuster and Funk','1966-01-31',NULL),(16,'Franz Bellfield','Phased client-server Graphic Interface','Cummings, Gerhold and Spinka','1931-01-03',NULL),(17,'Tilda Brimicombe','Organized static synergy','Hettinger Inc','1934-01-28',NULL),(18,'Korella Halt','Customizable hybrid installation','Batz, Dicki and Gorczany','1953-08-24',NULL),(19,'Vickie Gibbetts','Polarised background array','O\'Connell Group','2013-02-09',NULL),(20,'Ros Beecroft','Re-contextualized scalable implementation','Hoeger-Ward','1975-08-18',5),(21,'Maryjo Lamborn','Extended bandwidth-monitored initiative','Crona-Rodriguez','1999-04-05',NULL),(22,'Osmund','Object-based discrete data-warehouse','Pouros, Carter and VonRueden','2001-09-09',NULL),(23,'Hayes Benesevich','Public-key hybrid application','Sawayn Inc','1938-08-01',NULL),(24,'Josepha Greenhough','Re-contextualized 5th generation ability','Wisozk-Nikolaus','1957-08-01',NULL),(25,'Foss Cheak','Triple-buffered upward-trending pricing struc','Hagenes LLC','1954-07-05',NULL),(26,'Georges Jennaway','Cloned 5th generation contingency','Dibbert and Sons','1975-11-21',NULL),(27,'Juliet Le Galle','Face to face contextually-based migration','Gusikowski and Sons','1999-01-28',NULL),(28,'Myrah O\'Nion','Adaptive national emulation','Streich, Treutel and Harber','1979-06-29',NULL),(29,'Angele Dudley','Reverse-engineered actuating toolset','Emard LLC','1994-04-26',NULL),(30,'Weber Coite','Enhanced client-server product','Lesch, Beer and Luettgen','1987-03-06',NULL),(31,'Ileane Woolgar','Upgradable 24/7 time-frame','Stokes Group','1940-08-11',NULL),(32,'Barbara Natalie','Exclusive human-resource leverage','Emmerich LLC','1971-12-26',NULL),(33,'Gabi Castell','Focused homogeneous process improvement','Schultz-Hane','2007-08-04',12),(34,'Caren Maynell','Pre-emptive heuristic benchmark','Borer-Botsford','1941-11-05',NULL),(35,'Faustine Melvin','User-centric content-based local area network','Simonis and Sons','1955-12-16',NULL),(36,'Marjie Geale','Networked cohesive monitoring','Kshlerin, Davis and Torphy','1934-01-15',NULL),(37,'Urbano Thomasset','Expanded secondary encryption','Luettgen LLC','1932-03-13',NULL),(38,'Hildegarde Millom','Self-enabling methodical open architecture','Sipes, Balistreri and Bergstrom','1990-11-03',NULL),(39,'Mamie Dyzart','Assimilated 5th generation methodology','Lockman LLC','1949-01-23',NULL),(40,'Carney Mazzey','Cross-group system-worthy database','Ruecker-Feest','1988-01-18',NULL),(41,'Celinda Spillard','Distributed modular groupware','Goyette LLC','1945-03-09',NULL),(42,'Rodi Jenton','Reverse-engineered upward-trending toolset','Simonis-Bode','1959-01-05',NULL),(43,'Hali Sumbler','Ergonomic high-level moderator','Connelly Inc','2009-06-01',NULL),(44,'Feliza Sutcliffe','Distributed 5th generation focus group','Barrows-Abbott','2011-07-24',7),(45,'Wendeline Ronaghan','Horizontal national portal','Hartmann, Ebert and Feeney','1971-07-19',NULL),(46,'Rochelle De Gouy','Fully-configurable systemic help-desk','Mayer, Miller and Bashirian','1946-11-23',NULL),(47,'Edyth Couroy','Fully-configurable 24/7 customer loyalty','Mosciski-Greenholt','1938-08-10',NULL),(48,'Mano Ditzel','Fully-configurable content-based encryption','Kuhic and Sons','2013-12-10',NULL),(49,'Phyllys Mulkerrins','Synchronised content-based archive','Mayer, Connelly and Lueilwitz','1986-11-03',NULL),(50,'Raymund Mille','Secured local process improvement','Veum-Goyette','1960-04-24',NULL);
/*!40000 ALTER TABLE `book_catalog` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `customers`
--

DROP TABLE IF EXISTS `customers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `customers` (
  `id` int(11) NOT NULL,
  `fname` varchar(45) DEFAULT NULL,
  `lname` varchar(45) DEFAULT NULL,
  `phone` varchar(45) DEFAULT NULL,
  `address` varchar(70) DEFAULT NULL,
  `email` varchar(45) DEFAULT NULL,
  `birthday` date DEFAULT NULL,
  `amount_of_purcheses` int(11) DEFAULT '0',
  `date_of_register` date DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customers`
--

LOCK TABLES `customers` WRITE;
/*!40000 ALTER TABLE `customers` DISABLE KEYS */;
INSERT INTO `customers` VALUES (113650174,'Chadd','Henriet','8168544175','6 Prairieview Junction','chenrieto@linkedin.com','1970-01-19',1,'2016-01-01'),(131108649,'Barris','Josefowicz','3123027923','193 Sutherland Terrace','bjosefowicz1d@merriam-webster.com','1972-09-26',0,'2016-02-01'),(137911773,'Aurthur','Arkley','2712340096','3051 Bartillon Parkway','aarkleyu@salon.com','2001-03-25',2,'2016-03-01'),(138560604,'Daniel','Mawby','8244387754','359 Derek Junction','dmawbyt@yolasite.com','1975-09-20',0,'2016-01-02'),(196348605,'Siouxie','Isles','8169264022','4 Linden Center','sislesj@sina.com.cn','1989-10-20',0,'2016-02-02'),(206986762,'Floris','Hubbins','5730623919','3772 Hollow Ridge Hill','fhubbins6@canalblog.com','1975-11-26',0,'2016-03-02'),(217726316,'Dorene','Coase','1420004604','74 Debra Hill','dcoase16@google.es','1961-04-07',0,'2016-01-03'),(219433739,'Carleen','Beeke','8463207101','643 Jay Plaza','cbeekem@bluehost.com','2001-05-05',2,'2016-02-03'),(224603773,'Adham','Leggitt','2444785115','140 Scoville Trail','aleggittl@quantcast.com','2007-11-08',1,'2016-03-03'),(243022245,'Simona','Sawnwy','9742080272','3 Trailsway Lane','ssawnwy10@nasa.gov','2012-10-11',0,'2016-01-04'),(255099087,'Deana','Lissenden','1655560596','2636 Ilene Junction','dlissenden0@house.gov','2016-05-11',0,'2016-02-04'),(287473264,'Yvonne','Caplin','4651554541','7455 Lunder Drive','ycaplinc@photobucket.com','1968-04-18',0,'2016-03-04'),(306466242,'Alfie','Corballis','2643698459','9 Karstens Trail','acorballisq@unc.edu','1996-01-03',1,'2016-01-05'),(312927923,'Malorie','Wix','1879824875','0 Stang Pass','mwixd@drupal.org','1994-11-20',0,'2016-02-05'),(317444565,'Dee','Ludgate','7995133260','8468 Northridge Drive','dludgateg@umich.edu','1984-04-24',0,'2016-03-05'),(343140116,'Cristiano','Mewburn','2663574753','48 Namekagon Alley','cmewburn2@symantec.com','2007-09-24',0,'2016-01-06'),(378075469,'Leonhard','Renahan','2816895426','82652 Miller Drive','lrenahanw@networkadvertising.org','1996-01-24',0,'2016-02-06'),(397281560,'Rufus','Ravilious','1837243559','79 Granby Lane','rravilious1a@rambler.ru','2000-02-01',0,'2016-03-06'),(405695663,'Kissie','Lantaff','4497257253','95212 Graedel Junction','klantaffp@intel.com','1961-01-29',0,'2016-01-07'),(439739068,'Mariquilla','Huntingdon','2486626603','414 Bay Avenue','mhuntingdon13@earthlink.net','2011-12-18',0,'2016-02-07'),(461080892,'Reggie','Legion','3753773636','149 Bowman Plaza','rlegione@amazon.co.uk','2000-02-07',0,'2016-03-07'),(476859360,'Cleopatra','Pollins','2748469713','27 Lawn Terrace','cpollins8@51.la','1971-03-24',0,'2016-01-08'),(500435524,'Teena','Schiell','4058371090','303 Prairieview Lane','tschiellf@multiply.com','1982-12-28',0,'2016-02-08'),(502514682,'Jacquenette','Ruit','6021840609','9 Myrtle Drive','jruit12@digg.com','1978-04-22',0,'2016-03-08'),(531618814,'Emlyn','Binford','1590148238','4570 Knutson Parkway','ebinford9@nydailynews.com','1977-10-09',0,'2016-01-09'),(619890399,'Grete','Botcherby','8457367302','39957 Reindahl Trail','gbotcherby14@army.mil','1985-06-06',0,'2016-02-09'),(642264726,'Vale','Wallicker','9752100773','433 Mayer Crossing','vwallicker19@wufoo.com','2003-12-30',0,'2016-03-09'),(661677449,'Frederico','Baudone','6123422895','05218 Pond Junction','fbaudone17@un.org','1967-07-25',0,'2016-01-10'),(665645697,'Grata','Wooffitt','3090685718','044 Ludington Street','gwooffitty@blinklist.com','2008-11-13',0,'2016-02-10'),(671374272,'Bartolemo','Abad','1320545429','643 Bobwhite Crossing','babads@topsy.com','2001-02-15',0,'2016-03-10'),(683198325,'Tymothy','Laffan','6321322050','82 Veith Trail','tlaffanr@unc.edu','2005-07-21',0,'2017-01-11'),(695806357,'Leopold','Billings','2296712294','79 Forster Place','lbillingsx@icio.us','2011-01-13',0,'2017-02-11'),(716268525,'Hildegarde','Farrens','5857855397','258 Mallard Street','hfarrens11@zimbio.com','1975-01-31',0,'2017-03-11'),(763035801,'Alvan','Dunseath','7276298262','09 Towne Place','adunseath18@hc360.com','1961-05-31',0,'2017-01-12'),(766685029,'Jens','Clackers','5413995080','50 Hansons Plaza','jclackersh@tinyurl.com','1987-02-25',0,'2017-02-12'),(767349108,'Halsey','Gresly','9736768166','7 Granby Way','hgreslyv@ifeng.com','1987-01-25',0,'2017-03-12'),(815487946,'Hazel','Ferens','3113850481','070 Sutherland Road','hferensi@webs.com','2004-01-04',0,'2017-01-13'),(828354193,'Lilias','Cuncliffe','4128047223','9 Everett Trail','lcuncliffez@ucla.edu','1976-11-12',0,'2017-02-13'),(834752268,'Warde','Zorzini','4571677167','3051 Talisman Place','wzorzinik@tripod.com','1979-11-02',0,'2017-03-13'),(841808952,'Bryna','Vlahos','9270025511','62511 Pennsylvania Place','bvlahosa@domainmarket.com','2011-10-19',0,'2017-01-14'),(848971248,'Honor','Durnell','1928343259','3386 Logan Parkway','hdurnell15@reddit.com','2016-06-04',0,'2017-02-14'),(859456172,'Dionysus','Dorset','8816253341','423 Burrows Avenue','ddorsetn@live.com','1989-03-31',0,'2017-03-14'),(864858212,'Ursola','Guidetti','9343213406','7 Drewry Street','uguidetti5@google.ca','2015-02-24',0,'2017-01-15'),(868671267,'Nichole','Stainland','3640054313','44 Randy Circle','nstainland7@wordpress.org','1970-04-26',0,'2017-02-15'),(871410142,'Remington','Debling','7422685714','822 Northview Point','rdebling1c@t.co','1987-07-20',0,'2018-03-15'),(881598472,'Rebecca','McAvaddy','9187647749','23186 Burning Wood Lane','rmcavaddy3@lycos.com','1964-02-06',0,'2018-01-16'),(923665660,'Kimbell','Draisey','2237900149','99406 Glacier Hill Alley','kdraisey1@cnn.com','1984-06-06',0,'2018-02-16'),(930126887,'Cher','Scutchings','4608210275','93 Heath Street','cscutchingsb@cnet.com','1961-10-06',0,'2018-03-16'),(932548827,'Eleonore','Vanichkov','4801487739','0063 Fairview Parkway','evanichkov1b@spiegel.de','1976-07-28',0,'2018-01-17'),(994930323,'Leopold','Canadine','9189855137','59194 Gale Center','lcanadine4@techcrunch.com','1974-05-31',0,'2018-02-17');
/*!40000 ALTER TABLE `customers` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `order_statuses`
--

DROP TABLE IF EXISTS `order_statuses`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `order_statuses` (
  `status_id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`status_id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `order_statuses`
--

LOCK TABLES `order_statuses` WRITE;
/*!40000 ALTER TABLE `order_statuses` DISABLE KEYS */;
INSERT INTO `order_statuses` VALUES (1,'Orderd'),(2,'Arrived'),(3,'Customer notified'),(4,'Complete'),(5,'Canceled'),(6,'Turn into sale');
/*!40000 ALTER TABLE `order_statuses` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `orders`
--

DROP TABLE IF EXISTS `orders`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `orders` (
  `order_num` int(11) NOT NULL AUTO_INCREMENT,
  `Client_id` int(11) NOT NULL,
  `date_of_order` date DEFAULT NULL,
  `status` int(11) DEFAULT NULL,
  PRIMARY KEY (`order_num`),
  KEY `Client_id` (`Client_id`),
  KEY `status_id_idx` (`status`),
  CONSTRAINT `orders_ibfk_1` FOREIGN KEY (`Client_id`) REFERENCES `customers` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `orders`
--

LOCK TABLES `orders` WRITE;
/*!40000 ALTER TABLE `orders` DISABLE KEYS */;
INSERT INTO `orders` VALUES (1,439739068,'2016-01-20',1),(2,206986762,'2016-07-23',4),(3,317444565,'2017-03-09',4),(4,868671267,'2017-05-30',4),(5,868671267,'2018-01-12',6);
/*!40000 ALTER TABLE `orders` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `orders_books`
--

DROP TABLE IF EXISTS `orders_books`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `orders_books` (
  `order_id` int(11) NOT NULL,
  `ISBN` int(10) unsigned NOT NULL,
  `supplier_id` int(11) DEFAULT NULL,
  KEY `order_id_idx_1` (`order_id`),
  KEY `ISBN_idx_1` (`ISBN`),
  KEY `supplier_idfk_1_idx` (`supplier_id`),
  CONSTRAINT `book_isbn` FOREIGN KEY (`ISBN`) REFERENCES `book` (`ISBN`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `order_id` FOREIGN KEY (`order_id`) REFERENCES `orders` (`order_num`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `supplier_idfk_1` FOREIGN KEY (`supplier_id`) REFERENCES `suppliers` (`supplier_id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `orders_books`
--

LOCK TABLES `orders_books` WRITE;
/*!40000 ALTER TABLE `orders_books` DISABLE KEYS */;
INSERT INTO `orders_books` VALUES (2,40,2),(1,1,1),(5,3,2),(3,5,1),(4,7,1);
/*!40000 ALTER TABLE `orders_books` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `suppliers`
--

DROP TABLE IF EXISTS `suppliers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `suppliers` (
  `supplier_id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(45) DEFAULT NULL,
  `phone` varchar(45) DEFAULT NULL,
  `address` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`supplier_id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `suppliers`
--

LOCK TABLES `suppliers` WRITE;
/*!40000 ALTER TABLE `suppliers` DISABLE KEYS */;
INSERT INTO `suppliers` VALUES (1,'Kutar 1','0502777111','Ben gurion 20, tel-aviv'),(2,'Eli Books','039500382','Hatamar 19, Rishon Lezion'),(3,'Crown books','0774030268','Hanarkis 9, Ramat Hasharon');
/*!40000 ALTER TABLE `suppliers` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `supply_price_list`
--

DROP TABLE IF EXISTS `supply_price_list`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `supply_price_list` (
  `ISBN` int(10) unsigned NOT NULL,
  `supplier_id` int(11) NOT NULL,
  `price_per_book` int(11) DEFAULT NULL,
  KEY `supplier_id_idx` (`supplier_id`),
  KEY `isbn_idx` (`ISBN`),
  CONSTRAINT `supplier_id` FOREIGN KEY (`supplier_id`) REFERENCES `suppliers` (`supplier_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `supply_price_list`
--

LOCK TABLES `supply_price_list` WRITE;
/*!40000 ALTER TABLE `supply_price_list` DISABLE KEYS */;
INSERT INTO `supply_price_list` VALUES (1,1,28),(2,1,27),(3,2,37),(4,2,31),(5,1,40),(6,1,23),(7,1,37),(8,2,37),(9,1,20),(10,1,36),(11,1,35),(12,1,33),(13,1,33),(14,1,33),(15,1,22),(16,2,30),(17,1,39),(18,2,33),(19,2,26),(20,2,33),(21,1,25),(22,1,25),(23,1,39),(24,2,26),(25,2,34),(26,2,29),(27,3,24),(28,2,38),(29,2,35),(30,3,25),(31,3,33),(32,2,24),(33,3,26),(34,3,24),(35,3,20),(36,2,36),(37,2,35),(38,3,21),(39,2,27),(40,2,40),(41,3,22),(42,2,34),(43,3,26),(44,2,29),(45,3,29),(46,3,26),(47,3,26),(48,2,33),(49,3,32),(50,2,20);
/*!40000 ALTER TABLE `supply_price_list` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transactions`
--

DROP TABLE IF EXISTS `transactions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `transactions` (
  `trans_id` int(11) NOT NULL AUTO_INCREMENT,
  `issue_date` date DEFAULT NULL,
  `customer_id` int(11) DEFAULT NULL,
  `discount` double DEFAULT NULL,
  `total_price` double DEFAULT NULL,
  `status` int(11) DEFAULT NULL,
  PRIMARY KEY (`trans_id`),
  KEY `customer_id_idx` (`customer_id`),
  KEY `status_idx` (`status`),
  CONSTRAINT `customer_id` FOREIGN KEY (`customer_id`) REFERENCES `customers` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `status` FOREIGN KEY (`status`) REFERENCES `order_statuses` (`status_id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transactions`
--

LOCK TABLES `transactions` WRITE;
/*!40000 ALTER TABLE `transactions` DISABLE KEYS */;
INSERT INTO `transactions` VALUES (1,'2018-03-08',137911773,0,224,4),(2,'2017-09-09',219433739,20,144,5),(3,'2017-12-27',306466242,17,57,4),(4,'2017-03-09',219433739,10,93,4),(5,'2017-12-30',137911773,10,93,4),(6,'2017-01-01',137911773,0,93,4);
/*!40000 ALTER TABLE `transactions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transactions_books`
--

DROP TABLE IF EXISTS `transactions_books`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `transactions_books` (
  `trans_id` int(11) NOT NULL,
  `ISBN` int(10) unsigned NOT NULL,
  KEY `trans_id_idx` (`trans_id`),
  KEY `ISBN_idx` (`ISBN`),
  KEY `trans_id_idx2` (`trans_id`),
  KEY `ISBN_idx2` (`ISBN`),
  CONSTRAINT `book_id_h` FOREIGN KEY (`ISBN`) REFERENCES `book` (`ISBN`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `transa_id_h` FOREIGN KEY (`trans_id`) REFERENCES `transactions` (`trans_id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transactions_books`
--

LOCK TABLES `transactions_books` WRITE;
/*!40000 ALTER TABLE `transactions_books` DISABLE KEYS */;
INSERT INTO `transactions_books` VALUES (1,3),(1,2),(1,27),(2,14),(2,10),(3,44),(4,27),(5,27),(6,27);
/*!40000 ALTER TABLE `transactions_books` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-08-02 16:31:00
