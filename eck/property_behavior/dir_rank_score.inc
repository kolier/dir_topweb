<?php

/**
 * @file
 * ECK property_behavior: dir_rank_score.
 */

$plugin = array(
  'label' => t('Dir ranking score'),
  'default_widget' => 'dir_topweb_dir_rank_score_default_widget',
  'default_formatter' => 'dir_topweb_dir_rank_score_default_formatter',
);

/**
 * 'default_widget' callback.
 */
function dir_topweb_dir_rank_score_default_widget($property, $vars) {
  $entity = $vars['entity'];
  return array(
    '#type' => 'textfield',
    '#title' => $vars['properties'][$property]['label'],
    '#default_value' => isset($entity->{$property}) ? $entity->{$property} : 0,
    '#size' => 60,
    '#maxlength' => 128,
  );
}

/**
 * 'default_formatter' callback.
 */
function dir_topweb_dir_rank_score_default_formatter($property, $vars) {
  $entity = $vars['entity'];

  return array(
    '#markup' => strip_tags($entity->{$property}),
  );
}
