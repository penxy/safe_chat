PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS 'tbl_friend' (
    'index' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    'chatId' varchar(64) NOT NULL,
    'name' varchar(32) NOT NULL,
    'pix64' text NOT NULL
);
CREATE TABLE IF NOT EXISTS 'tbl_history' (
    'index' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    'chatId' varchar(64) NOT NULL,
    'dateTime' varchar(64) NOT NULL,
    'isSelf' BOOLEAN NOT NULL,
    'content' text NOT NULL
);
CREATE INDEX IF NOT EXISTS idx_tbl_friend ON tbl_friend (chatId);
CREATE INDEX IF NOT EXISTS idx_tbl_history ON tbl_history (chatId);
COMMIT;