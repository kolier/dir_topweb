<?php

/**
 * @file
 * ECK property_behavior: dir_rank_score.
 */

$plugin = array(
  'label' => t('Dir ranking score'),
  'default_widget' => 'dir_topweb_dir_rank_score_default_widget',
  'default_formatter' => 'dir_topweb_dir_rank_score_default_formatter',
  'bundle_form' => 'dir_topweb_dir_rank_score_property_bundle_form',
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

/**
 * 'bundle_form' callback.
 */
function dir_topweb_dir_rank_score_property_bundle_form($property, $vars) {
  $form = &$vars['form'];
  $eck_entity_type = $form['entity_type']['#value'];
  $eck_bundle = $form['bundle']['#value'];
  $config = $eck_bundle->config;

  $form['dir_rank_score'] = array(
    '#title' => t('Dir: Rank score'),
    '#type' => 'fieldset',
  );
  // Each entityreference property get a separate settings
  foreach ($eck_entity_type->properties as $name => $property) {
    if ($property['behavior'] == 'dir_rank_score') {
      $container = 'config_' . $name;
      $form['dir_rank_score'][$container] = array(
        '#type' => 'fieldset',
        '#title' => $property['label'],
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
        '#tree' => TRUE,
      );
      $form['dir_rank_score'][$container]['factor'] = array(
        '#title' => t('Score factor'),
        '#description' => t('Input the factor for the score.'),
        '#type' => 'textfield',
        '#size' => 255,
        '#default_value' => isset($config[$name]['factor']) ? $config[$name]['factor'] : '1',
        '#weight' => 0,
      );
    }
  }

  return $vars;
}