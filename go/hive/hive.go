package main

import (
	"github.com/derekgr/hivething"
	"github.com/usthooz/oozlog/go"
)

func main() {
	db, err := hivething.Connect("127.0.0.1:9083", hivething.DefaultOptions)
	if err != nil {
		ozlog.Errorf("Hive Connect err-> %v", err)
		return
	}
	defer db.Close()

	results, err := db.Query("show tables")

	if err != nil {
		ozlog.Errorf("Hive Query err-> %v", err)
		return
	}

	var (
		tableName string
	)
	for results.Next() {
		results.Scan(&tableName)
		ozlog.Infof("Table-> %s", tableName)
	}
}
