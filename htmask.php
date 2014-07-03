<?php
$hashes = array();
$funcs = get_defined_functions();
$mask = zend_hash_table_mask($funcs["internal"]);
foreach ($funcs["internal"] as $f) {
	$hashes[zend_hash_func($f) & $mask][] = $f;
}
print_r($hashes);
//print_r(array_filter($hashes, function($e) { return sizeof($e) > 1; }));
